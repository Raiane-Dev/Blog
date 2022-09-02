#include "../../includes/routes/Marker.hpp"

std::shared_ptr<Routes::Marker::OutgoingResponse> Routes::Marker::handle(const std::shared_ptr<IncomingRequest>& request)
{
    return ResponseFactory::createResponse(Status::CODE_200, "Hello");
}