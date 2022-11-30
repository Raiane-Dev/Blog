#include "../../includes/models/UserModel.hpp"

Models::UserModel::UserModel()
{

}

result Models::UserModel::hasOne( Models::UserProperties& data )
{
  std::string conditional = fmt::format("email = '{}' AND password = '{}'", data._email, data._password);

    Utils::Queries query{};
    query
        .from("users")
        .where(conditional)
        .method(Utils::Queries::type::select);

    result response = query.exec();

    return  response;
}

bool Models::UserModel::insert( Models::UserProperties& data )
{
    std::string send = fmt::format("('{}', '{}', '{}')", data._username, data._email, data._password);

    try
    {
        Utils::Queries query{};
        query
            .from("users")
            .values(send)
            .columns("username, email, password, role")
            .method(Utils::Queries::type::insert);

        auto body = query.exec();

        return true;
    }
    catch(const std::exception& err)
    {
        std::printf(err.what());
        return false;
    }

}

bool Models::UserModel::update( Models::UserProperties& body )
{
    return true;
}

result Models::UserModel::hasMany()
{
    Utils::Queries query{};
    query
        .from("users")
        .method(Utils::Queries::type::select);

    result response = query.exec();

    return  response;
}


Models::UserModel::~UserModel()
{

}