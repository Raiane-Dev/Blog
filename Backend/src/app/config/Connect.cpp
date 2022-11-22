#include "../../includes/config/Connect.hpp"



Config::Connect::Connect()
{
    std::stringstream line;
    line << "dbname=" << this->dbname <<
    " port=5432 " << "hostaddr=172.24.0.1" <<
    " user=" << this->dbuser << " password=" << this->dbpass;

    this->data_line = line.str();
}

void Config::Connect::transac()
{
    connection connect( this->data_line );
    work state(connect);
    state.exec(this->query);
    state.commit();

    std::printf("Executed transaction");
}

void Config::Connect::consult()
{
    connection connect( this->data_line );
    nontransaction state(connect);
    result ret( state.exec( this->query) );

    std::printf("Executed.");
}