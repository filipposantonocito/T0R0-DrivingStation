#ifndef GAMEPADMONITOR_H
#define GAMEPADMONITOR_H

#include <QtCore/QObject>
#include <QtCore/QTimer>

class QGamepad;

class GamepadMonitor : public QObject
{
    Q_OBJECT
public:
    explicit GamepadMonitor(QObject *parent = 0);
    ~GamepadMonitor();

private:
    QGamepad *m_gamepad;
};

#endif // GAMEPADMONITOR_H
