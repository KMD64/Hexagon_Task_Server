#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QUrl>
#include <QString>
#include <QMap>
struct HttpRequest{
    QString method;
    QUrl address;
    QString httpversion;
    QMap<QString,QString> headers;
    QString body;
    HttpRequest(const QString &src);
    operator bool();
};
#endif // HTTPREQUEST_H
