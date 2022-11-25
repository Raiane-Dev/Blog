#pragma once

#include <cstdlib>
#include <vector>
#include "../config/Connect.hpp"

namespace Utils
{
    class Queries : public Config::Connect
    {
        public:

            Queries();

            enum type
            {
                insert, update, remove, select
            };

            Queries& from(  std::string table );
            Queries& where( std::string clausules );
            Queries& method( type method );
            Queries& set( std::string data );
            Queries& values( std::string data );
            Queries& columns( std::string column );
            result exec();

    };
}