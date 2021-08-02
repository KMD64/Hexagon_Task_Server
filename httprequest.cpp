#include "httprequest.h"

HttpRequest::HttpRequest(const QString &src)
{
    try{
        if(src.isEmpty())throw std::runtime_error("Empty request");
        auto req_parts = src.splitRef("\r\n\r\n");//separate header from body
        //separate header lines
        auto header_parts = req_parts.at(0).split("\r\n");

        //first line is request info
        auto head = header_parts.at(0).split(" ");
        if(head.length()<3)throw std::runtime_error("Head syntax error");
        method=head.at(0).toString();
        address=head.at(1).toString();
        httpversion = head.at(2).toString();

        //parsing headers
        for(auto iter = header_parts.begin()+1;iter!=header_parts.end();++iter){
            auto kv = iter->split(": ");
            if(kv.length()==2){
                headers.insert(kv.at(0).toString(),kv.at(1).toString());
            }
        }
        body = req_parts.value(1).toString();
    }catch(std::exception e){
        //header init error;
        method="";
    }
}

HttpRequest::operator bool()
{
    return method.length()>0;//correct request should contain method
}
