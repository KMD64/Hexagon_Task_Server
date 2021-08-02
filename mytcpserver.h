#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QtNetwork/QTcpServer>

class MyHttpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyHttpServer(QObject *parent = nullptr);
    ~MyHttpServer();
    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle);
private:


};

#endif // MYTCPSERVER_H
