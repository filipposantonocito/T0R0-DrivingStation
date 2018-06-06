#include "window.h"
#include "ui.h"

#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <QKeyEvent>

//JOYSTICk//
//#include "joystick.h"


// Constructor
Window::Window(QWidget *parent) : QWidget(parent)
{
  ui = new WindowUi(this);
}

Window::~Window(){
  delete ui;
}


void Window::keyPressEvent (QKeyEvent *keyevent) {

  // CTRL + ALT + Q --> Quit the setApplicationName
  // R --> reload

	switch ( keyevent->key() ) {
	        case Qt::Key_R:                               // reload
	            qDebug("Pressed R");
	            update();
	            break;
	        case Qt::Key_Q:
              qDebug("Pressed Q");
	            key[0] = 1;
	            break;
         case Qt::Key_Alt:
              qDebug("Pressed Alt");
              key[1] = 1;
              break;
         case Qt::Key_Control:
              qDebug("Pressed Ctrl");
              key[2] = 1;
              break;

	    }

      if (key[0] && key[1] && key[2])
      {
        qDebug("Ctrl-Alt-Q all Pressed");
        QCoreApplication::quit();
      }
}

void Window::keyReleaseEvent (QKeyEvent *keyevent) {
  switch ( keyevent->key() ) {
        case Qt::Key_Q:
            qDebug("Released Q");
            key[0] = 0;
            break;
        case Qt::Key_Alt:
            qDebug("Released Alt");
            key[1] = 0;
            break;
        case Qt::Key_Control:
            qDebug("Released Ctrl");
            key[2] = 0;
            break;

      }
}
