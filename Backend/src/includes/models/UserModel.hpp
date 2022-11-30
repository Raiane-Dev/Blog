#pragma once

#include <string>
#include <fmt/core.h>
#include "../includes/utils/Queries.hpp"

namespace Models
{

    struct UserProperties
    {
        uint64_t _id;
        std::string _username;
        std::string _email;
        std::string _password;
    };

    class UserModel
    {
        public:
            UserModel();

            bool create( UserProperties& user ) const;

            bool insert( UserProperties& body );

            bool update( UserProperties& body );

            result hasMany();

            result hasOne( Models::UserProperties& body );

            ~UserModel();
    };
};