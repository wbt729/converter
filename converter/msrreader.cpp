#include "msrreader.h"

MSRReader::MSRReader() {
	stop = false;
	file = new QFile();
	bytesPerFrame = 0;
	framesInFile = 0;
	width = 0;
	height = 0;
	colorMode = 0;
	headerSize = 16;
	bitsPerChannel = 0;
	channels = 0;
	frameIndex = 0;

	//connect(this, SIGNAL(convertFrame(int)), this, SLOT(frameToTiff(int)));
}

MSRReader::~MSRReader() {

}

void MSRReader::setFile(QString path) {
	if(file->isOpen())
		file->close();
	file->setFileName(path);
	qDebug() << "MSRReader: open file" << path << file->open(QIODevice::ReadOnly);
	readFileInfo();
	//file->close();
}

void MSRReader::readFileInfo() {
	if(!file->isOpen()) {
		qDebug() << "MSRReader: cannot read file info, file not open";
		return;
	}
	qDebug() << "MSRReader: file size is" << file->size();
	
	QDataStream in(file);

	in.readRawData((char*) &colorMode, sizeof(int));
	qDebug() << "MSRReader: color mode is" << colorMode;

	switch(colorMode) {
		case 25:
			bitsPerChannel = 10;
			channels = 3;
			break;
		default:
			bitsPerChannel = 0;
			channels = 0;
	}

	in.readRawData((char*) &bytesPerFrame, sizeof(int));
	qDebug() << "MSRReader:" << bytesPerFrame << "bytes per frame";
	framesInFile = (file->size() - headerSize)/(bytesPerFrame+sizeof(unsigned long long));
	qDebug() << "MSRReader: number of frames in this file" << framesInFile;
	in.readRawData((char*) &height, sizeof(int));
	qDebug() << "MSRReader: height is" << height << "px";
	in.readRawData((char*) &width, sizeof(int));
	qDebug() << "MSRReader: width is" << width << "px";
	file->seek(sizeof(int));
	emit newFileInfo();
}

int MSRReader::getHeight() {
	return height;
}

int MSRReader::getWidth() {
	return width;
}

int MSRReader::getFileSize() {
	return file->size();
}

int MSRReader::getNumberOfFrames() {
	return framesInFile;
}

int MSRReader::getColorMode() {
	return colorMode;
}

//convert 10bit data to 8bit image for displaying
void MSRReader::makePreview(int frameNumber) {

	//convert to unsigned char since only bitshift ops on _unsigned_ 
	//values fill with zeros
	//qDebug() << "MSRReader: open file for preview " << file->open(QIODevice::ReadOnly);
	file->seek(headerSize+sizeof(unsigned long long)+frameNumber*(bytesPerFrame+sizeof(unsigned long long)));
	QDataStream in(file);

	//unsigned char *rawData = (unsigned char *) rawDat;
	unsigned char *rawData = new unsigned char[bytesPerFrame];
	in.readRawData((char*) rawData, bytesPerFrame);

	QImage image = QImage(width, height, QImage::Format_RGB888);
	image.fill(0);
	
	QVector<unsigned short> samples = readSamples(rawData);
	//shift right by two to get 8 bit values
	if(bitsPerChannel == 10 && channels == 3) {
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				image.setPixel(j,i,qRgb(samples[channels*(i*width+j)] >> 2,
										samples[channels*(i*width+j)+1] >> 2,
										samples[channels*(i*width+j)+2] >> 2));
			}
		}
	}
	else if(bitsPerChannel == 8 && channels == 1) {
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				image.setPixel(j,i,qRgb(samples[channels*(i*width+j)],
										samples[channels*(i*width+j)],
										samples[channels*(i*width+j)]));
			}
		}
	}
	emit newPreview(image);
	delete rawData;
}

//returns a vector of unsigned shorts that contains the samples with 10 bit precision
QVector<unsigned short> MSRReader::readSamples(unsigned char *rawData) {
	QVector<unsigned short> samples = QVector<unsigned short>(width*height*channels, 0); //preallocate memory and fill with zeros
	unsigned short r, g, b, gy;
	r = 0; g = 0; b = 0; gy = 0;

	int offset = 0;

	if(bitsPerChannel == 10 && channels == 3) {
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				r = 0; g = 0; b = 0;
				//bitwise magic
				//copies two bytes to short value in reverse order
				//due to endianess
				//10 bit value is determined by masking the bits that are not
				//part of the color channel and shifting the
				//remaining bits, so that 10 significant bits remain
				r = r | (rawData[offset+3] << 8);
				r = r | rawData[offset+2];
				r = (r & 0x3ff0) >> 4; //10 bit

				g = g | (rawData[offset+2] << 8);
				g = g | rawData[offset+1];
				g = (g & 0x0ffc) >> 2; //10 bit

				b = b | (rawData[offset+1] << 8);
				b = b | rawData[offset];
				b = (b & 0x03ff); //10 bit

				samples.replace(channels*(i*width+j), r);
				samples.replace(channels*(i*width+j)+1, g);
				samples.replace(channels*(i*width+j)+2, b);
				offset += 4;
			}
		}
	}
	else if(bitsPerChannel == 8 && channels == 1) {
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				gy = 0;
				gy = rawData[i*width+j];
				samples.replace(channels*(i*width+j), gy);
			}
		}
	}
	return samples;
}

void MSRReader::stopConverting() {
	stop = true;
}

void MSRReader::convertWholeFile() {
	stop = false;
	if(!file->isOpen()) {
		qDebug() << "MSRReader: cannot read, file not open";
		return;
	}
	frameIndex = 0;
	frameToTiff(frameIndex);
}

void MSRReader::onFrameConverted() {
	qDebug() << frameIndex;
	frameIndex++;
	if(frameIndex < framesInFile)
		//emit convertFrame(frameIndex);
		frameToTiff(frameIndex);
	else
		return;
}


void MSRReader::frameToTiff(int frameNumber) {
	if(!file->isOpen()) {
		qDebug() << "MSRReader: cannot read, file not open";
		return;
	}

	QDataStream in(file);
	
	//jump to frame offset
	file->seek(headerSize+frameNumber*(bytesPerFrame+sizeof(unsigned long long)));
	

	//read timestamp
	unsigned long long timestamp = 0;
	in.readRawData((char*) &timestamp, sizeof(unsigned long long));

	unsigned char *rawData = new unsigned char[bytesPerFrame];
	in.readRawData((char*) rawData, bytesPerFrame);

	QVector<unsigned short> samples = readSamples(rawData);

	//start cleaning tis mess here!

	//get string for filename
	QString extensionString = QString(tr(".tiff"));
	QStringList location = file->fileName().split(".");
	if(!QDir(location[0]).exists()) {
		QDir().mkdir(location[0]);
	}
	//one of the timestamps doesn't get extracted in the right way, therefore no file is created
	//QString filenameTIFF = location[0] + QString("/") + QString::number(timestamp) + extensionString;
	QString filenameTIFF = location[0] + QString("/") + QString::number(frameIndex) + extensionString;
	TIFF *out=TIFFOpen(filenameTIFF.toLatin1(),"w");

	TIFFSetField(out, TIFFTAG_IMAGEWIDTH, width);
	TIFFSetField(out, TIFFTAG_IMAGELENGTH, height);
	TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, channels);
	TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, bitsPerChannel);
	TIFFSetField(out, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
	TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);

	tsize_t linebytes = TIFFScanlineSize(out);
	unsigned char *buf=NULL;
	buf=(unsigned char*)_TIFFmalloc(linebytes);

	TIFFSetField(out, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(out, width*channels));
		
	char *newLine = new char[linebytes+10];
	for(int row=0; row<height; row++) {

		uchar buf[5];
		uchar sBuf[2];
		unsigned short s;
		int linePos = 0;
		for(int i=0; i<channels*width; i+=4) {
			//qDebug() << i;
			memset(&buf, 0, 5);
			for(int j=0; j<4; j++) {
				s = samples[row*width*channels+i+j];
				switch(j) {
					case 0:
						s = s << 6;
						sBuf[0] = (char) (s >> 8);
						sBuf[1] = (char) s;
						buf[0] = buf[0] | sBuf[0];
						buf[1] = buf[1] | sBuf[1];
						break;
					case 1:
						s = s << 4;
						sBuf[0] = (char) (s >> 8);
						sBuf[1] = (char) s;
						buf[1] = buf[1] | sBuf[0];
						buf[2] = buf[2] | sBuf[1];
						break;
					case 2:
						s = s << 2;
						sBuf[0] = (char) (s >> 8);
						sBuf[1] = (char) s;
						buf[2] = buf[2] | sBuf[0];
						buf[3] = buf[3] | sBuf[1];
						break;
					case 3:
						sBuf[0] = (char) (s >> 8);
						sBuf[1] = (char) s;
						buf[3] = buf[3] | sBuf[0];
						buf[4] = buf[4] | sBuf[1];
						break;
				}
			}
			for(int k=0; k<5; k++) {
				newLine[linePos+k] = buf[k];
			}
			linePos += 5;
		}
		//memcpy(buf, newLine, linebytes);
		//qDebug() << "writing row" << row;
		//if(TIFFWriteScanline(out, buf, row, 0)<0) {
		if(TIFFWriteScanline(out, newLine, row, 0)<0) {
			qDebug() << "something went wrong during writing the tiff";
		return;
		}

	}
	TIFFClose(out);


	delete rawData;
	emit frameConverted(frameNumber);
	QTimer::singleShot(0, this, SLOT(onFrameConverted()));	//allow for event procesing before converting next file
}