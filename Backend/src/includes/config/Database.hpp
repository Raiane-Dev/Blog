#include <oatpp/orm/DbClient.hpp>
#include <oatpp-postgresql/orm.hpp>
#include <oatpp-postgresql/Connection.hpp>

namespace Config
{
    class Database : public oatpp::orm::DbClient
    {
        public:
            Database( const std::shared_ptr<oatpp::orm::Executor>& executor )
            : oatpp::orm::DbClient(executor) {};
    
            OATPP_CREATE_COMPONENT(std::shared_ptr<Config::Database>, Config::Database) ( [] {
            auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>("postgresql://postgres:db-pass@localhost:5432/postgres");
    });
    
    };
};