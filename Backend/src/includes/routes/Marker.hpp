#pragma once

#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "../controllers/UserController.hpp"
#include "../controllers/ArticleController.hpp"

using namespace Pistache;
using namespace Rest;
using namespace Controllers;

namespace Router
{
    class Marker : public Http::Handler
    {
        private:
            Rest::Router router;
            HTTP_PROTOTYPE(Marker);

        public:
            Marker();

            void onRequest( const Http::Request&, Http::ResponseWriter writer) override;

            void init();
            void start();
            void settupRouter();

    };
};