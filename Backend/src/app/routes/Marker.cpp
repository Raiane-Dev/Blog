#include "../../includes/routes/Marker.hpp"

Router::Marker::Marker()
{
    Address addr(Ipv4::any(), Port(8088));
    Http::Endpoint server(addr);
    const auto opts = Http::Endpoint::options()
                    .threads(static_cast<int>(1));
    
    server.init(opts);
    this->settupRouter();
    server.setHandler(this->router.handler());
    server.serve();
}

void Router::Marker::onRequest( const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer)
{
    writer.send(Pistache::Http::Code::Ok, "Hello!");
};


void Router::Marker::settupRouter()
{
    Routes::Post(this->router, "/articles", Routes::bind( &ArticleController::create ));
    Routes::Get(this->router, "/articles", Routes::bind( &ArticleController::list ));

    Routes::Post(this->router, "/login", Routes::bind( &UserController::login ));
    Routes::Get(this->router, "/login", Routes::bind( &Middleware::Authentication::checker ));

    Routes::Post(this->router, "/register", Routes::bind( &UserController::create ));

}