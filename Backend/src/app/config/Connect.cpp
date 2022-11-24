#include "../../includes/config/Connect.hpp"

Config::Connect::Connect()
{
    
}

result Config::Connect::instanceOf()
{
    std::stringstream dataline;
    result ret;

    dataline <<  "dbname=" << this->dbname <<
                    " port=5432 " << "hostaddr=" << this->dbhost <<
                    " user=" << this->dbuser << " password=" << this->dbpass;

    try
    {
        connection connect(dataline.str());
        if( connect.is_open() )
        {
            std::printf("CONECTADO");
        }
        work db(connect);
        this->database = &db;
        ret = this->database->exec(this->query);
    }
    catch( const std::exception &err )
    {
        std::printf(err.what());

        std::abort();
    }

    return ret;

}
