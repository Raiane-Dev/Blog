#pragma once

#include <string>
#include <iostream>

#include <botan/botan.h>
#include <botan/bcrypt.h>
#include <openssl/crypto.h>
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

            static std::string serializeCrypt( std::string pass );

            static bool verifyCrypt( std::string pass, std::string hash );
    
            ~Tratament();
    };

}