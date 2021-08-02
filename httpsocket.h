#ifndef HTTPSOCKET_H
#define HTTPSOCKET_H

#include <QTcpSocket>
#include "httprequest.h"
#include "httpresponse.h"
#include <QUrl>

class HttpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit HttpSocket(QObject *parent = nullptr);
private slots:
    void handleRequest();
};

#endif // HTTPSOCKET_H
