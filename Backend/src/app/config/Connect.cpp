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
        std::string sql = this->sanitize();
        ret = this->database->exec(sql);
        this->database->commit();
    }
    catch( const std::exception &err )
    {
        std::printf(err.what());

        std::abort();
    }

    return ret;

}

std::string Config::Connect::sanitize()
{
    std::string create_sql;

    sort(this->query.begin(), this->query.end());
    for( auto value : this->query )
    {
        create_sql.append( " " + value.second + " " );
    }

    std::printf(create_sql.c_str());
    return create_sql;
};