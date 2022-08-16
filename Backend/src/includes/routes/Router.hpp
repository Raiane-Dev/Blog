#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPResponse.h>

class Router
{
    public:
        Router();

        Poco::Net::HTTPRequestHandler* RequestHandled( const Poco::Net::HTTPServerRequest& request );

        ~Router();
};