#pragma  once

#include "../routes/Marker.hpp"
#include <nlohmann/json.hpp>
#include "../models/ArticleModel.hpp"

using namespace Pistache;
using namespace Models;

namespace Controllers
{
    namespace ArticleController
    {
        void list( const Rest::Request&, Http::ResponseWriter response );
        
        void create( const Rest::Request& request, Http::ResponseWriter response );

    };
};