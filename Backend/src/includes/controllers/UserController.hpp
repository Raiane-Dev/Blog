#pragma once

#include <exception>
#include "../utils/Tratament.hpp"
#include "../routes/Marker.hpp"
#include "../models/UserModel.hpp"

using namespace Pistache;
using namespace Models;

namespace Controllers
{

    namespace UserController
    {
        void list( const Rest::Request&, Http::ResponseWriter response );

        void login( const Rest::Request&, Http::ResponseWriter response );
        
        void create( const Rest::Request& request, Http::ResponseWriter response );
    };
};