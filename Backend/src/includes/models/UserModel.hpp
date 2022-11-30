#pragma once

#include <string>
#include <fmt/core.h>
#include "../includes/utils/Queries.hpp"
#include "../includes/utils/Tratament.hpp"

namespace Models
{

    struct UserProperties
    {
        uint64_t _id;
        std::string _username;
        std::string _email;
        std::string _password;
        std::string _role;
    };

    class UserModel
    {
        public:
            UserModel();

            bool create( UserProperties& user ) const;

            bool insert( UserProperties& body );

            bool update( UserProperties& body );

            result hasMany();

            bool hasOne( Models::UserProperties& body );

            ~UserModel();
    };
};