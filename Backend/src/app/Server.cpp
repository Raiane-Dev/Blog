#include <iostream>
#include <cstdlib>

#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>

// #include "../includes/routes/Marker.hpp"
#include "../includes/config/Database.hpp"

void run()
{

    const std::string host = "localhost";
    const uint16_t port = 8088;
    /**
     * Router for HTTP request routing
     */
    auto router = oatpp::web::server::HttpRouter::createShared();
    // Routes::Marker routerMark = Routes::Marker{};
    Config::Database;
    
    /**
     * HTTP connection handler with router
     */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
    
    /**
     * TCP connection provider
     */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({
        host, port, oatpp::network::Address::IP_4
    });

    /**
     * Server which takes provided TCP connections and passes
     */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /**
     * Started server
     */
    server.run();
}

int main( int argc, char** argv )
{

    /**
     * Init oatpp Enviroment
     */
    oatpp::base::Environment::init();

    /**
     * Run app
     */
    run();

    oatpp::base::Environment::destroy();

    return 0;
}