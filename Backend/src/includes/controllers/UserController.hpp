#pragma once

#include <exception>
#include <iostream>
#include "../middleware/Authentication.hpp"
#include "../utils/Tratament.hpp"
#include "../routes/Marker.hpp"
#include "../models/UserModel.hpp"

using namespace Pistache;
using namespace Models;

namespace Controllers
{

    namespace UserController
    {
        void list( const Rest::Request& request, Http::ResponseWriter response );

        void login( const Rest::Request& request, Http::ResponseWriter response );
        
        void create( const Rest::Request& request, Http::ResponseWriter response );
    };
};