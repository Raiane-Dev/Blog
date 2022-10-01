#include <iostream>
#include <cstdlib>

#include <pistache/endpoint.h>

#include "../includes/routes/Marker.hpp"
#include "../includes/config/Connect.hpp"
#include "../includes/config/Logger.hpp"

using namespace Pistache;
using namespace Routes;


void run()
{

    const std::string host = "localhost";
    const uint16_t port = 8088;

}

int main( int argc, char** argv )
{

    Config::Connect *db = new Config::Connect();
    new Config::Logger();
    // Http::listenAndServe<Marker>(Pistache::Address("*:8088"));

    return 0;
}