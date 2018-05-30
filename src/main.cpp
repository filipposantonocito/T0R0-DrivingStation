#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QTextCodec>

#include "window.h"

int main(int argc, char **argv)
{
  QCoreApplication::setApplicationName("T0R0 GUI DRIVING STATION");
	QApplication app(argc, argv);


	QDesktopWidget *desktop = app.desktop();
	Window window(desktop->screenGeometry());
 	window.showFullScreen();

	//choose url of camera.
	window.openUrl();

  //show message on console.
	qDebug() << "\nWindow opened successfully\n";

	return app.exec();
}
