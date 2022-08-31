#include "../../includes/controllers/UserController.hpp"

// Controllers::UserController::handle()
// {
    // return ResponseFactory::createResponse(Status::CODE_200, "Hello");
// }

auto Controllers::UserController::store( Models::UserProperties &user )
{
    user._id = 10029;
};