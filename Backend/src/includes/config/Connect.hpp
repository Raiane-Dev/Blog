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
            const char* dbname = std::getenv("POSTGRES_DB");
            const char* dbuser = std::getenv("POSTGRES_USER");
            const char* dbpass = std::getenv("POSTGRES_PASSWORD");

            std::string data_line;

        protected:
            connection connect;
            work database;

        public:
            Connect(): connect(this->data_line), database(this->connect)
            {
                 try
                {
                    std::stringstream line;
                    // line << "dbname=" << this->dbname <<
                    // " port=5432 " << "hostaddr=172.20.2.0" <<
                    // " user=" << this->dbuser << " password=" << this->dbpass;

                    line << "dbname=" << "blog" <<
                    " port=5432 " << "hostaddr=0.0.0.0" <<
                    " user=" << "admin" << " password=" << "root";

                    this->data_line = line.str();
                } 
                catch(const std::exception &e)
                {
                    std::printf(e.what());
                }
            }

            ~Connect();
    };
}