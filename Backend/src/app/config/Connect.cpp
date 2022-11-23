#include "../../includes/config/Connect.hpp"

Config::Connect::~Connect()
{
    this->connect.close();
}