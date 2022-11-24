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

            Queries& from(  std::string table );
            Queries& where( std::vector<std::string> clausules );
            Queries& method( std::string method );
            Queries& set( std::string data );
            Queries& values( std::string data );
            Queries& columns( std::string column );
            result exec();

    };
}