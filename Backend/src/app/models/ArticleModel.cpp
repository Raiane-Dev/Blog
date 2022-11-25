#include "../../includes/models/ArticleModel.hpp"

Models::ArticleModel::ArticleModel()
{

}

bool Models::ArticleModel::insert( std::string data )
{
    Utils::Queries query{};
    query
        .from("articles")
        .values(data)
        .columns("title, body")
        .method(Utils::Queries::type::insert);
        
    auto body = query.exec();

    return true;
}

bool Models::ArticleModel::update( std::string body )
{
    return true;
}

Models::ArticleModel::~ArticleModel()
{

}