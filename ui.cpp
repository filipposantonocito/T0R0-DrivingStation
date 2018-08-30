#include "ui.h"
#include "voipvideowidget.h"
#include "config.h"

#include <QDebug>
#include <QString>
#include <QLabel>
#include <QPainter>

WindowUi::WindowUi(QWidget *parent) : QWidget(parent)
{
    CreateUI();

    //Gstremer://
    //Set port of the camera
    camera1_videoWidget->setPort(1234);

    //START VIDEO
    camera1_videoWidget->startPipeline();
    qDebug() << "\nVideo started successfully\n";
    /////////////

    //* CAMERAs BUTTON *//
    // Create the button, make "this" the parent
    videoSwitchZedL = new QPushButton("ZED Left", this);
    videoSwitchZedR = new QPushButton("ZED Right", this);
    videoSwitchTurret = new QPushButton("Turret Cam", this);
    videoSwitchArm = new QPushButton("Arm Cam", this);

    // set size and location of the button
    videoSwitchZedL->   setGeometry(QRect(QPoint(100, ( (this->height()-CAMERA_HEIGHT) /2) +30, QSize(100, 50) )));
    videoSwitchZedR->   setGeometry(QRect(QPoint(210, ( (this->height()-CAMERA_HEIGHT) /2) +30, QSize(100, 50) )));
    videoSwitchTurret-> setGeometry(QRect(QPoint(320, ( (this->height()-CAMERA_HEIGHT) /2) +30, QSize(100, 50) )));
    videoSwitchArm->    setGeometry(QRect(QPoint(430, ( (this->height()-CAMERA_HEIGHT) /2) +30, QSize(100, 50) )));

    //// >>>> @todo connect to MQTT handler. Publish command.
    // Connect button signal to appropriate slot
    // connect(videoSwitchZedL,   SIGNAL (released()), this, SLOT (videoSwitch(1)));
    // connect(videoSwitchZedR,   SIGNAL (released()), this, SLOT (videoSwitch(2)));
    // connect(videoSwitchTurret, SIGNAL (released()), this, SLOT (videoSwitch(3)));
    // connect(videoSwitchArm,    SIGNAL (released()), this, SLOT (videoSwitch(4)));

}

WindowUi::~WindowUi(){
}

//UI://
void WindowUi::CreateUI()
{
    this->setGeometry(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    qDebug() << "MainWindow set to " << this->width() << "x" << this->height();

    // set black background
    QPalette pal = palette();

    // Set backgroud color
    pal.setColor(QPalette::Background, QColor(14,14,14,255));
    this->setAutoFillBackground(true);
    this->setPalette(pal);


    // Show Team D.I.A.N.A. logo at bottom-right
    // add images to resources.qrc to use them//
    // http://doc.qt.io/qt-5/resources.html //
    QLabel *pixlogo = new QLabel(this);
    QPixmap pixmaplogo(":/Images/diana-logo-193x90.png");
    int w = 193;
    int h = 90;
    pixlogo->setPixmap(pixmaplogo.scaled(w, h, Qt::KeepAspectRatio));
    pixlogo->setGeometry( this->width() - 238, this->height() - 120, w, h );

    //Gstremer://
    camera1_videoWidget = new VoipVideoWidget(this);
    camera1_videoWidget->setGeometry( (this->width()-CAMERA_WIDTH)/2, (this->height()-CAMERA_HEIGHT)/2, CAMERA_WIDTH, CAMERA_HEIGHT );
    /////////////

    //JOYSTICK://
    dpanic_lnl = new QLabel(this);
    dpanic_lnl->setGeometry(0, 12, this->width(), 25);
    dpanic_lnl->setAlignment(Qt::AlignCenter);
    dpanic_lnl->setText("DON'T PANIC");
    dpanic_lnl->setStyleSheet( "color : white;" );
    //////////

    /* ARM */
    joystickdisplay = new JoystickDisplay(this);
    joystickdisplay->setGeometry(45, this->height()-350, 254, 273);
    //joystickdisplay->show();
    ///////

    /* MOBILITY */
    gamepaddisplay = new GamepadDisplay(this);
    gamepaddisplay->setGeometry(45, this->height()-620, 110, 253);
    //gamepaddisplay->show();
    ///////
}
