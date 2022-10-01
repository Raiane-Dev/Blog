#include <ctime>

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

namespace Config
{

    class Logger
    {
        private:
            enum Severity
            {
                none = 0,
                fatal = 1,
                error = 2,
                warning = 3,
                info = 4,
                debug = 5,
                verbose = 6
            };


        public:
            Logger();
            
            ~Logger();
    };
}