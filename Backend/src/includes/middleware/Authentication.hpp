#pragma once

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <jwt-cpp/jwt.h>
#include <pistache/router.h>

namespace Middleware
{

    namespace Authentication
    {
        void checker( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response );

        void generate( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response );
    };

};