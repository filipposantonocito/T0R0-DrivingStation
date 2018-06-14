#-------------------------------------------------
#
# Project created by QtCreator 2018-06-14T17:54:02
#
#-------------------------------------------------

QT += core gui
QT += gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = T0-R0-drivingstation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#delete me
#include(src/include.pri)


# Now tell qmake to link to QtGStreamer and also use its include path and Cflags.
contains(QT_VERSION, ^4\\..*) {
  PKGCONFIG += QtGStreamer-1.0 QtGStreamerUi-1.0
}
contains(QT_VERSION, ^5\\..*) {
  PKGCONFIG += Qt5GStreamer-1.0 Qt5GStreamerUi-1.0
  QT += widgets
}

DISTFILES += \
    src/include.pri

FORMS += \
    src/window.ui

HEADERS += \
    src/gamepad.h \
    src/joystick.h \
    src/TcpClient.h \
    src/TcpServer.h \
    src/ui.h \
    src/voipvideowidget.h \
    src/window.h

SOURCES += \
    src/gamepad.cpp \
    src/joystick.cpp \
    src/main.cpp \
    src/TcpClient.cpp \
    src/TcpServer.cpp \
    src/ui.cpp \
    src/voipvideowidget.cpp \
    src/window.cpp

MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

DESTDIR = build
