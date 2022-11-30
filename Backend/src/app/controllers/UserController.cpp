#include "../../includes/controllers/UserController.hpp"

void Controllers::UserController::login( const Rest::Request& request, Http::ResponseWriter response )
{
     const std::string body = request.body();
    rapidjson::Document data;
    data.Parse(body.c_str());
    assert(data.IsObject());
    Models::UserProperties schema{ };
    schema._email = data["email"].GetString();
    schema._password = Utils::Tratament::serializeCrypt( data["password"].GetString() );

    try
    {
        Models::UserModel model{};
        result values = model.hasOne( schema );

        if( values.size() != 0 )
        {
            auto token = Middleware::Authentication::generate();

            response
                .cookies()
                .add(Pistache::Http::Cookie("x-access-token", token));
            
            response
                .send(Http::Code::Accepted, "logged" + schema._password);
        }
        else
        {
            response.send(Http::Code::Unauthorized, "User not exists.");
        }
    }
    catch( const std::exception &err)
    {
        response.send(Http::Code::Bad_Gateway, err.what());
    }
}

void Controllers::UserController::create( const Rest::Request& request, Http::ResponseWriter response )
{
    const std::string body = request.body();
    rapidjson::Document data;
    data.Parse(body.c_str());
    assert(data.IsObject());
    Models::UserProperties schema{
        1,
        data["username"].GetString(), 
        data["email"].GetString(),
        Utils::Tratament::serializeCrypt( data["password"].GetString() )
    };

    try
    {
        Models::UserModel model{};
        model.insert( schema );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    response.send(Http::Code::Created, body);
}

void Controllers::UserController::list( const Rest::Request&, Http::ResponseWriter response )
{
    
}