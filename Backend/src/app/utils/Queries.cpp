#include "../../includes/utils/Queries.hpp"

Utils::Queries::Queries()
{
}

Utils::Queries& Utils::Queries::method( std::string method )
{
    return *this;
}

Utils::Queries& Utils::Queries::set( std::string data )
{
    return *this;
}

Utils::Queries& Utils::Queries::values( std::string data )
{
    return *this;
}

Utils::Queries& Utils::Queries::columns( std::string column )
{
    std::string sql = column;

    this->query.append(sql);
    return *this;
}

Utils::Queries& Utils::Queries::where( std::vector<std::string> clausules )
{
    std::stringstream sql;

    for( auto clausule : clausules )
    {
        /**
         * @clausule0 COLUMN_ONE
            * @clausule1 OPERATOR
            * @clausule2 COLUMN_TWO
            * @clausule3 AND | OR
            */
        sql << clausule[0] +clausule[1] + clausule[2] + clausule[3];
    }

    this->query.append("WHERE " + sql.str());
    return *this;
}

Utils::Queries& Utils::Queries::from( std::string table )
{
    std::string sql = "SELECT * FROM " + table;
    this->query.append( sql );
    return *this;
}

result Utils::Queries::exec()
{
    result response = this->instanceOf();

    return response;

}