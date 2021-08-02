#include "httpsocket.h"
#include "requestdispatcher.h"

HttpResponse::operator QString()
{
    return "";
}

HttpSocket::HttpSocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this,&QIODevice::readyRead,&HttpSocket::handleRequest);
}

void HttpSocket::handleRequest()
{
    //read request
    HttpResponse resp;
    auto req_str = QString(read(16*1024));
    auto request = HttpRequest(req_str);
    RequestDispatcher dispatcher(request,resp);


}
