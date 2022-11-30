#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include <jwt-cpp/jwt.h>
#include <pistache/router.h>

namespace Middleware
{

    namespace Authentication
    {
        bool checker( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response );

        std::string generate();
    };

};