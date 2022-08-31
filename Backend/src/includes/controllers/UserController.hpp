#pragma once

#include "../models/UserModel.hpp"

#include <oatpp/web/server/HttpRequestHandler.hpp>

namespace Controllers
{

    class UserController : public oatpp::web::server::HttpRequestHandler
    {
        public:

            auto store( Models::UserProperties &user );

            std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override
            {
                return ResponseFactory::createResponse(Status::CODE_200, "Hello");
            }
    };
};