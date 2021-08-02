#include <QCoreApplication>
#include "mytcpserver.h"
#include <QtNetwork/QHostAddress>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyHttpServer srv;
    srv.listen(QHostAddress::LocalHost,1234);
    return a.exec();
}
