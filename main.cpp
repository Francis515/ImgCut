#include "ImgCut.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImgCut w;
	w.show();
	return a.exec();
}
