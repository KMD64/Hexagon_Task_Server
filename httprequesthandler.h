#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include <QtNetwork/QTcpSocket>
#include <QMap>
#include <QUrl>
struct HttpRequest{
    QString method;
    QUrl address;
    QString httpversion;
    QMap<QString,QString> headers;
    QString body;
    HttpRequest(const QString &src);
    operator bool();
};
struct HttpResponse{
    unsigned int status;
    QMap<QString,QString> headers;
    QString body;
    operator QString();
};
class HttpRequestHandler:public QObject
{
    Q_OBJECT
public:
    HttpRequestHandler();
signals:
    void responseReady();
public slots:
    void handleRequest();
};

#endif // HTTPREQUESTHANDLER_H
