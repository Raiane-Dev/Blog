#pragma once

#include <exception>
#include <cstdlib>
#include <pqxx/pqxx>

using namespace pqxx;

namespace Config
{
    class Connect
    {
        private:
            // const char* dbname = std::getenv("POSTGRES_DB");
            // const char* dbuser = std::getenv("POSTGRES_USER");
            // const char* dbpass = std::getenv("POSTGRES_PASSWORD");

        public:
            Connect();

           work* database;
            // static connection instanceOf();

            virtual ~Connect();
    };
}