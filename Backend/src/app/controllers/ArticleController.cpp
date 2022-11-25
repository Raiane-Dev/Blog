#include "../../includes/controllers/ArticleController.hpp"

void Controllers::ArticleController::create( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    const std::string body = request.body();
    auto data = nlohmann::json::parse(body);

    Models::ArticleProperties values{data};
    nlohmann::json convert_data = data;

    try
    {
        Models::ArticleModel model{};
        model.insert( convert_data );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    response.send(Http::Code::Created, body);
}

void Controllers::ArticleController::list(  const Rest::Request&, Http::ResponseWriter response )
{

    response.send(Http::Code::Accepted, "Hellow");
}