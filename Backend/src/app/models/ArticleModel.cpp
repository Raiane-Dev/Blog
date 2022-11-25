#include "../../includes/models/ArticleModel.hpp"

Models::ArticleModel::ArticleModel()
{

}

bool Models::ArticleModel::insert( Models::ArticleProperties& data )
{
    std::string send = fmt::format("('{}', '{}')", data.title, data.body);

    try
    {
        Utils::Queries query{};
        query
            .from("articles")
            .values(send)
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

Models::ArticleModel::~ArticleModel()
{

}