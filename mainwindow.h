#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "joystick.h"
#include "TcpClient.h"

//GAMEPAD//
//#include "gamepad.h"
#include <QtGamepad/QGamepad>

#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class WindowUi;

//JOYSTICK://
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

    //* INPUT *//
    Joystick *jstick, *gamepad;
    //////////

public Q_SLOTS:
    //

protected:

    void keyPressEvent(QKeyEvent *keyevent);
    void keyReleaseEvent (QKeyEvent *keyevent);
    int key[3]={0,0,0};

private:
    WindowUi *ui;

    TcpClient *client_wheel_FL, *client_wheel_FR, *client_wheel_RL, *client_wheel_RR;

    void ChangeText_Button(int n, int pressed);
    void ChangeText_Axis(int n, int position);

    void GamepadChangeText_Button(int n, int pressed);
    void GamepadChangeText_Axis(int n, int position);
};

#endif // MAINWINDOW_H
