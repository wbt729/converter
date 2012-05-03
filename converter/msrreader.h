#ifndef MSRREADER_H
#define MSRREADER_H

#include <QObject>
#include <QDebug>
#include <qcoreapplication.h>
#include <QFile>
#include <qimage.h>
#include <qtimer.h>
#include "tiff.h"
#include "tiffio.h"
#include "qstringlist.h"
#include <qdir.h>

class MSRReader : public QObject
{
	Q_OBJECT

public:
	MSRReader();
	~MSRReader();
	void setFile(QString);
	void readFileInfo();
	int getWidth();
	int getHeight();
	int getFileSize();
	int getNumberOfFrames();
	int getColorMode();
	void makePreview(int);
	QVector<unsigned short> readSamples(unsigned char*);
	
	void stopConverting();

private:
	bool stop;
	QFile *file;
	int bytesPerFrame, framesInFile, width, height;
	int colorMode;
	int headerSize;
	int channels;
	int frameIndex;
	int bitsPerChannel;

signals:
	void newFileInfo();
	void newPreview(QImage);
	void convertFrame(int);
	void frameConverted(int);
	void doneConvertingFile();
	void conversionStatus(int);

private slots:
	void convertWholeFile();
	void onFrameConverted();
	void frameToTiff(int);
};

#endif // MSRREADER_H
