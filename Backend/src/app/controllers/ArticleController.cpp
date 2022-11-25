#include "../../includes/controllers/ArticleController.hpp"

void Controllers::ArticleController::create( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    const std::string body = request.body();
    rapidjson::Document data;
    data.Parse(body.c_str());
    assert(data.IsObject());
    Models::ArticleProperties schema{
        std::time(NULL),
        data["title"].GetString(), 
        data["body"].GetString() 
    };

    try
    {
        Models::ArticleModel model{};
        model.insert( schema );
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