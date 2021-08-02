#include "mytcpserver.h"
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include <QThread>
#include "httpsocket.h"

MyHttpServer::MyHttpServer(QObject *parent):QTcpServer(parent)
{

}


MyHttpServer::~MyHttpServer()
{

}

void MyHttpServer::incomingConnection(qintptr handle)
{
    auto socket = new HttpSocket(this);
    socket->setSocketDescriptor(handle);
    qDebug()<<"Got connection:"<<socket->peerAddress()<<":"<<socket->peerPort();
}

