#include "converter.h"

converter::converter(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QString rPath = QString("/");

	dirModel = new QFileSystemModel(this);
	dirModel->setRootPath(rPath);
    dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    ui.tree->setModel(dirModel);
    ui.tree->setSortingEnabled(true);
    ui.tree->hideColumn(1);
    ui.tree->hideColumn(2);
    ui.tree->hideColumn(3);

    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::Files | QDir::NoDot | QDir::NoDotDot);
    fileModel->setNameFilters(QStringList(QString("*.msr")));
    fileModel->setNameFilterDisables(false);	// don't show filtered files, setting this to true only show them grayed out
    ui.list->setViewMode(QListView::ListMode);
    ui.list->setModel(fileModel);

	reader = new MSRReader();
	QThread *readerThread = new QThread();
	readerThread->start();
	reader->moveToThread(readerThread);

    connect(ui.tree, SIGNAL(clicked(QModelIndex)), this, SLOT(onNewDirSelected(QModelIndex)));
    connect(ui.list, SIGNAL(clicked(QModelIndex)), this, SLOT(onNewFileSelected(QModelIndex)));
	connect(reader, SIGNAL(newFileInfo()), this, SLOT(onFileInfo()));
	connect(reader, SIGNAL(newPreview(QImage)), this, SLOT(onPreview(QImage)));
	connect(ui.slider, SIGNAL(valueChanged(int)), this, SLOT(onSlider(int)));
	connect(ui.pushButtonConvert, SIGNAL(clicked()), reader, SLOT(convertWholeFile()));
	connect(reader, SIGNAL(frameConverted(int)), this, SLOT(onFrameConverted(int)));
}

converter::~converter()
{

}

void converter::onNewDirSelected(QModelIndex i) {
	QString sPath = dirModel->fileInfo(i).absoluteFilePath();
	qDebug() << "dir changed" << sPath;
	ui.list->setRootIndex(fileModel->setRootPath(sPath));
	fileModel->setNameFilters(QStringList(QString("*.msr")));	// workaround, name filter has to be cleared of sPath

}

void converter::onNewFileSelected(QModelIndex i) {
	QString path = fileModel->fileInfo(i).absoluteFilePath();
	qDebug() << "file clicked" << path;
	if(path.contains(".msr")) {
		reader->setFile(path);
	}
}

void converter::onConvertButton() {
	qDebug() << "convert button clicked";
	QItemSelectionModel *selectionModel= ui.list->selectionModel();
	QModelIndexList indices = selectionModel->selectedIndexes();
	if(!indices.isEmpty()) {
		QString path = fileModel->fileInfo(indices[0]).absoluteFilePath();
		qDebug() << "converting" << path;
	}
	else {
		qDebug() << "nothing selected";
	}
}

void converter::onFileInfo() {
	ui.labelHeight->setText(QString::number(reader->getHeight()));
	ui.labelWidth->setText(QString::number(reader->getWidth()));
	ui.labelFrames->setText(QString::number(reader->getNumberOfFrames()));

	switch(reader->getColorMode()) {
		case 25:
			ui.labelColorMode->setText("10 Bit RGB");
			break;
		default :
			ui.labelColorMode->setText("n/A");
	}
	reader->makePreview(0);
}

void converter::onPreview(QImage image) {
	QPixmap pixmap = QPixmap::fromImage(image);
	pixmap = pixmap.scaled(ui.labelPreview->width(), ui.labelPreview->height(), Qt::KeepAspectRatio);
	ui.labelPreview->setPixmap(pixmap);
}

void converter::onSlider(int value) {
	int frame = (int) (((double)reader->getNumberOfFrames()/100)*value);
	qDebug() << "MSRReader: making preview for frame" << frame;
	reader->makePreview(frame);
}

void converter::onFrameConverted(int frame) {
	ui.progressBar->setMaximum(reader->getNumberOfFrames());
	if(frame == reader->getNumberOfFrames()-1)
		ui.progressBar->setValue(ui.progressBar->maximum());
	else
		ui.progressBar->setValue(frame);
	return;
}