#include "../../includes/middleware/Authentication.hpp"

bool Middleware::Authentication::checker( const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response )
{
    std::string token = request.cookies().get("x-access-token").value;

    if( token != "" )
    {
        auto verifier = jwt::verify()
                            .allow_algorithm( jwt::algorithm::hs256{ std::getenv("SECRET") } )
                            .with_type("JWS")
                            .with_issuer("auth0");

        auto decoded = jwt::decode(token);
        verifier.verify( decoded );

        response.send(Pistache::Http::Code::Accepted, decoded.get_payload());
        if( !decoded.get_payload().empty() )
        {
            std::cout << "LOGADO";
            return true;
        }
    }
    else
    {
        std::cout << "NAO LOGADO";
        return false;
    }
}

std::string Middleware::Authentication::generate()
{
    auto token = jwt::create()
                        .set_issuer("auth0")
                        .set_type("JWS")
                        .set_payload_claim("sample", jwt::claim(std::string("test")))
                        .set_issued_at(std::chrono::system_clock::now())
                        .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{36000})
                        .sign(jwt::algorithm::hs256{ std::getenv("SECRET") });

    return token;

}

