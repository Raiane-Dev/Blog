#pragma  once

#include <vector>
#include <exception>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "../routes/Marker.hpp"
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