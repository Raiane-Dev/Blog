#ifndef static_files_hpp
#define static_files_hpp

#include <oatpp/core/Types.hpp>
#include <oatpp/core/data/stream/BufferStream.hpp>
#include <oatpp/core/data/stream/FileStream.hpp>

#include <unordered_map>

namespace Utils
{
    class Statics
    {
        private:
            oatpp::String m_resDir;
            std::unordered_map<oatpp::String, oatpp::String> m_resources;
            bool m_streaming;
            
            oatpp::String loadFromFile(const char* filename);
            void cacheFile(const char* filename);

            class ReadCallback : public oatpp::data::stream::ReadCallback
            {
                private:
                    oatpp::String m_file;
                    oatpp::data::stream::FileInputStream m_stream;

                public:
                    ReadCallback(const oatpp::String& file);
                    oatpp::v_io_size read(void *buffer, v_buff_size count, oatpp::async::Action& action) override;
            };

        public:
            Statics(const oatpp::String& resDir, bool streaming = false);

            static std::shared_ptr<Statics> cacheFiles(const oatpp::String& resDir)
            {
                auto res = std::make_shared<Statics>(resDir);

                res->cacheFile("test.html");

                return res;
            }

            oatpp::String getFile(const oatpp::String& filename);
            std::shared_ptr<ReadCallback> getFileStream(const oatpp::String& filename);

            bool isStreaming()
            {
                return m_streaming;
            }
    };
};