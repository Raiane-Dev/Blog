#include <cstdlib>

#include "../config/Connect.hpp"

namespace Utils
{
    class CommandQuery : public Config::Connect
    {
        private:
            typedef Config::Connect Super;

        public:
            CommandQuery();

            void getter(  const char* sql );
            void  setter(  const char* sql );

            ~CommandQuery();
    };
}