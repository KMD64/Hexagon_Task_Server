#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <QUrl>
#include <QString>
#include <QMap>

struct HttpResponse{
    unsigned int status;
    QMap<QString,QString> headers;
    QString body;
    operator QString();
};

#endif // HTTPRESPONSE_H
