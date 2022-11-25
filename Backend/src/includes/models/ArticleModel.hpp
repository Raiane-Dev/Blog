#pragma once

#include <vector>
#include <string>
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

            bool insert( std::string body );

            bool update( std::string body );

            ~ArticleModel();
    };
};