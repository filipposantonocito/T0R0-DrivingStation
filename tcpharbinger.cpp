#include "tcpharbinger.h"

#include <QDebug>



TcpHarbinger::TcpHarbinger(QWidget *parent, const char* _address, int _startPort, int _nConnections)  : QThread(parent)
{
    nConnections = _nConnections;
    startPort = _startPort;
    address = _address;

    m_loop = true;

    // Create TCP connection for each axis
    for (int i=0; i < nConnections; i++) {
        vecClients[i] = connect();
    }
    // Initialize Axis to zero
    for (int i=0; i < nConnections; i++) {
        vecClients[i]->send16(32767);   // Initialize to neutral value (= 32767)
        vecData16[i] = 32767;
        vecDataOld[i] = 32767;
    }
}

TcpHarbinger::~TcpHarbinger()
{
    stopLoop();
    usleep(200000);
}

void TcpHarbinger::run () {

    qDebug() << "TcoHarbinger: Starting Loop";

    while (m_loop)  // Loop -> if  m_loop = true
    {
        for (int i=0; i < nConnections; i++)      // Read data array and send trough TCP
        {
            if(!vecClients[i]->isConnected())   // If connection closed, reconnect
                    {
                        vecClients[i] = reconnect(i);

                        if (!vecClients[i]->isConnected()) vecTrials[i]++;  // Count failed trials
                        else vecTrials = 0;

                        if (vecTrials[i] < 10)  // Increase retrial time
                            usleep(5e5);
                        else if (vecTrials[i] < 25)
                            usleep(4e6);
                        else if (vecTrials[i] < 60)
                            usleep(10e6);
                        else
                            usleep(20e6);

                    }
            else if(vecClients[i] != NULL) {      // Send data
                if(vecData16[i] != vecDataOld[i])   // Don't resend same data
                {
                    if (!m_wait)
                    {
                        vecClients[i]->send16((uint16_t) vecData16[i]);
                        vecDataOld[i] = vecData16[i];
                        qDebug() << "Send data " << i << " : " <<  (int) vecData16[i];
                    }
                }
            }

        }
        usleep(100000); // Microseconds
    }
    qDebug() << "TcoHarbinger: Loop Terminated";
}

void TcpHarbinger::stopLoop()
{
  m_loop = false;
}

void TcpHarbinger::resume()
{
  m_wait = false;
}

void TcpHarbinger::suspend()
{
  m_wait = true;
}

int TcpHarbinger::writeData16 (int connectionId, int16_t value)
{
  int retStatus = 0;
  if (connectionId < nConnections && connectionId >= 0)
    vecData16[connectionId] = (uint16_t) value + 32768;
  else
    retStatus = -1;

  return retStatus; // return 0 if OK, -1 if problem is encuntered
}

int16_t TcpHarbinger::readLastAxisValue (int axis)
{
    return (int16_t) vecData16[axis] - 32768;
}

TcpClient* TcpHarbinger::connect(int index)
{
    qDebug() << "TCP["<< index <<"]: estabilshing TCP port: [" << startPort + index << "]";
    vecClients[index] = new TcpClient(address, startPort + index);
}

TcpClient* TcpHarbinger::reconnect(int index)
{
    delete vecClients[index];
    qDebug() << "TCP["<< index <<"] reconnecting: estabilshing TCP port \tADDRESS: " << address " [" << startPort + index << "]";
    vecClients[index] = new TcpClient(address, startPort + index);
}
