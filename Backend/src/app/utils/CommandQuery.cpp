#include "../../includes/utils/CommandQuery.hpp"

Utils::CommandQuery::CommandQuery()
{

}

void Utils::CommandQuery::setter( const char* sql )
{
    Super::query = sql;

    Super::transac();
}

void Utils::CommandQuery::getter( const char* sql )
{
    Super::query = sql;

    Super::consult();
}