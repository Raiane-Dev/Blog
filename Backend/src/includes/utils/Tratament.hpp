#pragma once

#include <string>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <pqxx/pqxx>

namespace Utils
{
    class Tratament
    {
        public:
            Tratament();

            static std::string serializeJson( pqxx::result data, std::string* columns );
    
            ~Tratament();
    };

}