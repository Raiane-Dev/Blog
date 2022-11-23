#include "../../includes/controllers/ArticleController.hpp"

void Controllers::ArticleController::create( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    const std::string body = request.body();

    response.send(Http::Code::Created, body);
}

void Controllers::ArticleController::list(  const Rest::Request&, Http::ResponseWriter response )
{

    response.send(Http::Code::Accepted, "Hellow");
}