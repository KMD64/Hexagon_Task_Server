#ifndef REQUESTDISPATCHER_H
#define REQUESTDISPATCHER_H
#include "httprequest.h"
#include "httpresponse.h"

class RequestDispatcher
{
public:
    RequestDispatcher(const HttpRequest&,HttpResponse &);
};

#endif // REQUESTDISPATCHER_H
