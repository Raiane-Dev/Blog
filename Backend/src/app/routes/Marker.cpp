#include "../../includes/routes/Marker.hpp"

void Router::Marker::onRequest( const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer)
{
    writer.send(Pistache::Http::Code::Ok, "Hello!");
};

void Router::Marker::settupRouter()
{
    Routes::Post(router, "/", Routes::bind( &UserController::create, this ));
}