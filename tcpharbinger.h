#ifndef TCPHARBINGER_H
#define TCPHARBINGER_H

#include <QObject>
#include <QWidget>
#include <QThread>

#include "TcpClient.h"
#include "config.h"

#define MAX_TCP_ELEMENTS 10

// nBytes = 1 or nBytes = 2 for the moment

class TcpHarbinger : public QThread
{
    Q_OBJECT

public:
    explicit TcpHarbinger(QWidget *parent = 0, const char* _address = "127.0.0.1", int startPort = 8080, int _nConnections = 1);
    ~TcpHarbinger();


    void stopLoop();        // Stop tcpLoop()
    void resume();
    void suspend();

    int writeData16(int connectionId, int16_t value);

    TcpClient* connect (int index);
    TcpClient* reconnect (int index);

    int16_t readLastAxisValue (int axis);

protected:
    void run();

private:
    int nConnections, startPort;

    TcpClient *vecClients[MAX_TCP_ELEMENTS];
    int vecTrials[MAX_TCP_ELEMENTS];

    uint16_t  vecData16[MAX_TCP_ELEMENTS], vecDataOld[MAX_TCP_ELEMENTS];

    bool m_loop;
    bool m_wait;
    const char* address;
};

#endif // TCPHARBINGER_H
