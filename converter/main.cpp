#include "converter.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	converter w;
	w.show();
	return a.exec();
}
