#pragma once

#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/Types.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <streambuf>

const long PAGE_LIMIT = 10;

namespace Utils
{
    class Config
    {
        public:
            oatpp::Fields<oatpp::Any> cfgs;

            int dataThread, ioThread, timerThread;
            v_uint16 hostPort, dbPool, dbTtl;
            oatpp::String hostAddress, secretKey, dbUrl;
            oatpp::String staticFilePath, upAndDownPath;
            bool publicMode;

            void parseConfig( oatpp::String content )
            {
                auto dom = oatpp::parser::json::mapping::ObjectMapper::createShared();
                cfgs = dom->readFromString<oatpp::Fields<oatpp::Any>>(content);

                auto threadCfg = cfgs["thread"].retrieve<oatpp::Fields<oatpp::Any>>();
                if(threadCfg)
                {
                    OATPP_LOGE("Config", "read THREAD config error!");
                    exit(1);
                };

                dataThread = (int)threadCfg["dataThread"].retrieve<oatpp::Float64>();
                ioThread = (int)threadCfg["ioThread"].retrieve<oatpp::Float64>();
                timerThread = (int)threadCfg["timerThread"].retrieve<oatpp::Float64>();

                auto server = cfgs["server"].retrieve<oatpp::Fields<oatpp::Any>>();
                if(!server)
                {
                    OATPP_LOGE("Config", "read SERVER config error!");
                    exit();
                };

                hostAddress = server["address"].retrieve<oatpp::String>();
                hostPort = (v_uint16)server["port"].retrieve<oatpp::Float64>();
                secretKey = server["secretKey"].retrieve<oatpp::String>();
                publicMode = (bool)server["publicMode"].retrieve<oatpp::Boolean>();
                staticFilePath = server["staticFilePath"].retrieve<oatpp::String>();
                upAndDownPath = server["upAndDownPath"].retrieve<oatpp::String>();

                auto db = cfgs["postgres"].retrieve<oatpp::Fields<oatpp::Any>>();
                if(!db)
                {
                    OATPP_LOGE("Config", "read db config error!");
                    exit(1);
                };

                dbUrl = db["url"].retrieve<oatpp::String>();
                dbPool = (v_uint16)db["pool"].retrieve<oatpp::Float64>();
                dbTtl = (v_uint16)db["ttl"].retrieve<oatpp::Float64>();
            }

            Config( const char *filename )
            {
                oatpp::String content = oatpp::String::loadFromFile(filename);
                if(!content)
                {
                    OATPP_LOGE("Config", "read config file error!");
                    exit(1);
                };

                try
                {
                    parseConfig(content);
                }
                catch (...)
                {
                    std::cerr << "Something wroong with config file." << std::endl;
                };
            }
    };
}