#pragma once

#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "../controllers/UserController.hpp"

using namespace Pistache;
using namespace Rest;
using namespace Controllers;

namespace Router
{
    class Marker : public Pistache::Http::Handler
    {
        private:
            Rest::Router router;

        public:
            HTTP_PROTOTYPE(Marker);

            void onRequest( const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer) override;

            void settupRouter();

    };
};