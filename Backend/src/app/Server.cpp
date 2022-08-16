#include <iostream>
#include <vector>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace std;

class PageHandler: public Poco::Net::HTTPRequestHandler
{

    public:
        void handleRequest(
            Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response
        ) {
            response.setChunkedTransferEncoding(true);
            response.setContentType("text/html");

            std::ostream& responseStream = response.send();

            responseStream << "<html><head> <title> MY SERVER HTTP </title> </head>";
            responseStream << "<body> <h1> MY BODY </h1> </body>";
            responseStream << "</html>";
        };
};

class HandleFactory: public Poco::Net::HTTPRequestHandlerFactory
{
    public:
        Poco::Net::HTTPRequestHandler* createRequestHandler( const Poco::Net::HTTPServerRequest& request )
        {
            if(request.getURI() == "/")
            {
                return new PageHandler();
            }

            return new PageHandler();
        }
};

class ServerApplication: public Poco::Util::ServerApplication
{
    protected:
        int main( const std::vector<std::string> &args )
        {
            Poco::UInt16 port = 9999;

            Poco::Net::ServerSocket socket(port);
            
            Poco::Net::HTTPServerParams *pParams = new Poco::Net::HTTPServerParams();

            pParams->setMaxQueued(100);
            pParams->setMaxThreads(16);

            Poco::Net::HTTPServer server(new HandleFactory(), socket, pParams);

            server.start();
            waitForTerminationRequest();
            server.stop();

            return EXIT_OK;
        }
};


POCO_SERVER_MAIN(ServerApplication);