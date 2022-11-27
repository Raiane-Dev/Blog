#pragma once

#include <string>
#include <fmt/core.h>
#include "../includes/utils/Queries.hpp"

namespace Models
{
    struct ArticleProperties
    {
        int id;
        std::string title;
        std::string body;
    };

    class ArticleModel
    {
        public:
            ArticleModel();

            bool insert( ArticleProperties& body );

            bool update( ArticleProperties& body );

            result hasMany();

            ~ArticleModel();
    };
};