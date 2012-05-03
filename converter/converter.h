#ifndef CONVERTER_H
#define CONVERTER_H

#include <QtGui/QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QGridLayout>
#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QProgressBar>
#include <msrreader.h>
#include <qtablewidget.h>
#include <QHeaderView>
#include "ui_converter.h"
#include <qthread.h>

class converter : public QMainWindow
{
    Q_OBJECT

public:
    converter(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~converter();

private:
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QPushButton *convertButton;
    QProgressBar *progressBar;
	MSRReader *reader;
	QTableWidget *table;
	Ui::converterClass ui;
	QLabel *labelConverting;

private slots:
	void onNewDirSelected(QModelIndex);
	void onNewFileSelected(QModelIndex);
	//void onConvertButton();
	void onFileInfo();
	void onPreview(QImage);
	void onSlider(int);
	void onFrameConverted(int);
	void onConversionStatus(int);
};

#endif // CONVERTER_H