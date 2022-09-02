#pragma once

#include <iostream>
#include <oatpp/web/server/HttpRequestHandler.hpp>

namespace Routes
{
    class Marker : public oatpp::web::server::HttpRequestHandler
    {
        public:
            std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
    };
};