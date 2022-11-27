#include "../../includes/controllers/ArticleController.hpp"

void Controllers::ArticleController::create( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    const std::string body = request.body();
    rapidjson::Document data;
    data.Parse(body.c_str());
    assert(data.IsObject());
    Models::ArticleProperties schema{
        1,
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

void Controllers::ArticleController::list( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    try
    {
        Models::ArticleModel model{};
        result values = model.hasMany();
        
        std::string columns[] = {"id", "title", "body", "createdAt"};
        std::string ret_json = Utils::Tratament::serializeJson( values, columns );

        response.send(Http::Code::Accepted, ret_json);
    }
    catch( const std::exception& err)
    {
        std::cerr << err.what() << "\n";
        response.send(Http::Code::Failed_Dependency, err.what());
    }

}