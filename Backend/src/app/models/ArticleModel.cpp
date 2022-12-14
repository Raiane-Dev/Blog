#include "../../includes/models/ArticleModel.hpp"

Models::ArticleModel::ArticleModel()
{

}

bool Models::ArticleModel::insert( Models::ArticleProperties& data )
{
    std::string send = fmt::format("('{}', '{}', '{}', '{}')", data.title, data.body, data.category, data.tags);

    try
    {
        Utils::Queries query{};
        query
            .from("articles")
            .values(send)
            .columns("title, body, category, tags")
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

bool Models::ArticleModel::update( Models::ArticleProperties& body )
{
    return true;
}

result Models::ArticleModel::hasMany()
{
    Utils::Queries query{};
    query
        .from("articles")
        .method(Utils::Queries::type::select);

    result response = query.exec();

    return  response;
}


Models::ArticleModel::~ArticleModel()
{

}