#pragma once
#include <cstdlib>
#include <string>

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

            bool create( UserProperties& user ) const;
    };
}