#pragma once

#include <list>
#include <string>

namespace Models
{
    struct ArticleProperties
    {
        int id;
        std::string name;
    };

    class ArticleModel
    {
        public:
            ArticleModel();

            bool insert(  ArticleProperties& body );

            bool update(  ArticleProperties& body );

            ~ArticleModel();
    };
};