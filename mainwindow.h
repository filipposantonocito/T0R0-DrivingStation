#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "joystick.h"
#include "TcpClient.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class WindowUi;

//INPUT://
class Joystick;
//////////

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //INPUT://
    Joystick *jstick;
    //////////

public Q_SLOTS:
    //

protected:

    void keyPressEvent(QKeyEvent *keyevent);
    void keyReleaseEvent (QKeyEvent *keyevent);
    int key[3]={0,0,0};

private:
    WindowUi *ui;

    TcpClient *left_client, *right_client;

    void ChangeText_Button(int n, int pressed);
    void ChangeText_Axis(int n, int position);
};

#endif // MAINWINDOW_H
