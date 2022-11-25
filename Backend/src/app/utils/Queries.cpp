#include "../../includes/utils/Queries.hpp"

/**
 * SELECT * FROM <TABLE> WHERE <CONDITIONAL>
 * INSERT INTO <TABLE> <COLUMNS> VALUES <VALUES>
 * UPDATE <TABLE> SET <DATA> WHERE <CONDITIONAL>
 * DELETE <TABLE> WHERE <CONDITIONAL>
 */
Utils::Queries::Queries()
{
}

Utils::Queries& Utils::Queries::method( Utils::Queries::type method )
{
    std::string sql;

    switch(method)
    {
        case insert:
            sql = "INSERT INTO";
            break;
        case update:
            sql = "UPDATE";
            break;
        case select:
            sql = "SELECT * FROM";
            break;
        case remove:
            sql = "DELETE";
            break;
    }

    this->query.push_back(
        std::make_pair(0, sql)
    );
    return *this;
}

Utils::Queries& Utils::Queries::from( std::string table )
{
    this->query.push_back(
        std::make_pair(1, table)
    );
    return *this;
}

Utils::Queries& Utils::Queries::set( std::string data )
{
    std::string sql = "SET (" + data + ")";

    this->query.push_back(
        std::make_pair(3, sql)
    );
    
    return *this;
}

Utils::Queries& Utils::Queries::values( std::string data )
{
    std::string sql = "VALUES ('" + data + "')";

    this->query.push_back(
        std::make_pair(3, sql)
    );

    return *this;
}

Utils::Queries& Utils::Queries::columns( std::string column )
{
    this->query.push_back(
        std::make_pair(2,"(" + column + ")")
    );

    return *this;
}

Utils::Queries& Utils::Queries::where( std::string clausules )
{
    std::stringstream sql;
    sql << clausules;

    this->query.emplace_back(
        std::make_pair(5, "WHERE " + sql.str())
    );

    return *this;
}

result Utils::Queries::exec()
{
    result response = this->instanceOf();

    return response;

}