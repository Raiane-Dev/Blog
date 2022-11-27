#include "../../includes/controllers/UserController.hpp"

void Controllers::UserController::login( const Rest::Request&, Http::ResponseWriter response )
{
    try
    {
        Models::UserModel model{};
        result values = model.hasOne();

        std::string columns[] = {"username", "email"};
        std::string ret_json = Utils::Tratament::serializeJson( values, columns );

        response.send(Http::Code::Accepted, ret_json);
    }
    catch( const std::exception &err)
    {
        response.send(Http::Code::Bad_Gateway, err.what());
    }
}

void Controllers::UserController::create( const Rest::Request&, Http::ResponseWriter response )
{
    
}

void Controllers::UserController::list( const Rest::Request&, Http::ResponseWriter response )
{
    
}