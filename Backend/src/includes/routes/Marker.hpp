#pragma once

#include <iostream>
#include <pistache/endpoint.h>
namespace Routes
{
    class Marker : public Pistache::Http::Handler
    {
        HTTP_PROTOTYPE(Marker);

        void onRequest( const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer) override
        {
            writer.send(Pistache::Http::Code::Ok, "Hello world!");
        }
    };
};