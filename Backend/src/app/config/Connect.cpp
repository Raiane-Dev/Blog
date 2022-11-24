#include "../../includes/config/Connect.hpp"

Config::Connect::Connect()
{
    std::stringstream dataline;

    dataline <<  "dbname=" << "blog" <<
                    " port=5432 " << "hostaddr=172.20.2.0" <<
                    " user=" << "admin" << " password=" << "root";

    // try
    // {
        connection connect(dataline.str());
        if( connect.is_open() )
        {
            std::printf("CONECTADO");
        }
        work db(connect);
        this->database = &db;
    // }
    // catch( const std::exception &err )
    // {
    //     std::printf(err.what());
    // }

}

Config::Connect::~Connect()
{
}