#include "../../includes/models/UserModel.hpp"

Models::UserModel::UserModel()
{

}

bool Models::UserModel::hasOne( Models::UserProperties& data )
{
  std::string conditional = fmt::format("email = '{}'", data._email);

    Utils::Queries query{};
    query
        .from("users")
        .where(conditional)
        .method(Utils::Queries::type::select);

    result response = query.exec();

    if(Utils::Tratament::verifyCrypt(data._password, response[0][2].c_str()))
    {
        return true;
    }
    else
    {
        return  false;
    }
}

bool Models::UserModel::insert( Models::UserProperties& data )
{
    std::string send = fmt::format("('{}', '{}', '{}', '{}')", data._username, data._email, data._password, data._role);

    try
    {
        Utils::Queries query{};
        query
            .from("users")
            .values(send)
            .columns("name, email, password, role")
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