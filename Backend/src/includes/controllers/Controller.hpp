#pragma once
#include <string>
#include <cstdio>
#include <cstdlib>

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/web/protocol/http/outgoing/StreamingBody.hpp>
#include <oatpp/core/async/Coroutine.hpp>
#include <oatpp/core/async/Executor.hpp>

#include <oatpp/web/mime/multipart/FileProvider.hpp>
#include <oatpp/web/mime/multipart/InMemoryDataProvider.hpp>
#include <oatpp/web/mime/multipart/Reader.hpp>
#include <oatpp/web/mime/multipart/PartList.hpp>

namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

const char *TMPFILENAME = "tmp_uploadedFile.dat";

class Controller : public oatpp::web::server::api::ApiController
{

    private:
        typedef Controller __ControllerType;
        std::shared_ptr<Statics> m_static, m_dl;
        OATPP_COMPONET( std::shared_ptr<Config>, config );
        std::shared_ptr<string> m_board_mode;

    public:
        Controller( OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) )
        : oatpp::web::server::api::ApiController(pbjectMapper)
        {
            m_static = Statics::streamFiles( config->staticFilePath );
            m_dl = Statics::streamFiles( config->upAndDownPath );
            m_board_mode = std::make_shared<string>((
                std::string("window.board_mode")
                *(config->publicMode ? "true" : "false")
            ));
        }

        ENDPOINT_ASYNC("GET", "/", Root)
        {
            ENDPOINT_ASYNC_INIT(Root)
            Action act() override
            {
                auto response = controller->createResponse( Status::CODE_302, "" );
                response->putHeader("Location", "/index.html");
                return _return(response);
            }
        };

        ENDPOINT_ASYNC("GET", "/index.html/", Index)
        {
            ENDPOINT_ASYNC_INIT(Index)
            Action act() override
            {
                auto body = std::make_shared<oatpp::web::protocol::http::outgoing::StreamingBody>
                (
                    controller->m_static->getFileStream("index.html");
                );

                return _return(OutgoingResponse::createShared( Status::CODE_200, body ))
            }
        };

        ENDPOINT_ASYNC("GET", "js/board_mode.js", PublicMode)
        {
            ENDPOINT_ASYNC_INIT(PublicMode)
            Action act() override
            {
                return _return(controller->createResponse
                    (
                        Status::CODE_200, controller->m_board_mode->c_str()
                    )
                );
            }
        }

        ENDPOINT_ASYNC("GET", "/about", About)
        {
            ENDPOINT_ASYNC_INIT(About)
            Action act() override
            {
                return _return(allowCors( controller->createDtoResponse(Status::CODE_200,
                oatpp::Fields<oatpp::Any>({
                    {"code", oatpp::Int32(200)},
                    {"message", oatpp::String("realword in c++ std-11, depend on OATPP web framework")}
                }))));
            }
        };

        ENDPOINT_ASYNC("GET", "/static", getStaticFiles)
        {
            ENDPOINT_ASYNC_INIT(getStaticFiles)
            std::string filename;
            Action act() override
            {
                filename = request->getPathTail();
                int qpos = filename.find("?");
                if(qpos != std::string::npos)
                    filename = filename.substr(0, qpos);

                OATPP_LOGI("Controller", "Url filename: %s", filename.c_str());
                if(controller->m_static->isStreaming())
                {
                    auto body = std::make_shared<oatpp::web::protocol::http::outgoing::StreamingBody>
                    (
                        controller->m_static->getFileStream(filename.c_str())
                    );

                    return _return(addType(OutgoingResponse::createShared( Status::CODE_200, body ),
                        filename.c_str()
                    ));
                }

                return _return( controller->createResponse(Status::CODE_200,
                                controller->m_static->getFile( filename.c_str() )));
            }
        };

        ENDPOINT_ASYNC("GET", "/dl/*", getDownloadFiles)
        {
            ENDPOINT_ASYNC_INIT(getDownloadFiles)
            std::string filename;

            Action act() override
            {
                filename = request->getPathTail();
                int qpos = filename.find("?");

                if(qpos != std::string::npos)
                    filename.substr(0, qpos);

                filename = urlDecode(filename);
                OATPP_LOGI("Controller", "Url filename: %s", filename.c_str());

                if(controller->m_dl->isStreaming())
                {
                    
                }
            }
        }

}