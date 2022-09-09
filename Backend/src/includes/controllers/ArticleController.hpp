#pragma once

#include <string>
#include <cstdio>
#include <cstdlib>

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/web/protocol/http/outgoing/StreamingBody.hpp>
#include <oatpp/core/async/Coroutine.hpp>
#include <oatpp/core/async/Executor.hpp>
#include <oatpp/web/protocol/http/incoming/Request.hpp>

#include <oatpp/web/mime/multipart/FileProvider.hpp>
#include <oatpp/web/mime/multipart/InMemoryDataProvider.hpp>
#include <oatpp/web/mime/multipart/Reader.hpp>
#include <oatpp/web/mime/multipart/PartList.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class ArticleController : public oatpp::web::server::api::ApiController
{
    private:
        typedef ArticleController __ControllerType;
        const ArticleService m_articleService;
        OATPP_COMPONENT(std::shared_ptr<Config>, config);

    public:
        typedef oatpp::web::protocol::http::Status Status;
        ArticleController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper)
        {
            slugify_init();
        }

        ENDPOINT_ASYNC("POST", "/api/articles", NewArticle)
        {
            ENDPOINT_ASYNC_INIT(NewArticle)
            Action act() override
            {
                return request->readBodyToDtoAsync<oatpp::Object<NewArticleDto>>
                (
                    controller->getDefaultObjectMapper()
                ).callbackTo(&NewArticle::act1);
            }

            Action act1( const oatpp::Object<NewArticleDto>& nad )
            {
                auto ua = UserAuth::fromAuthHeader(request);

                if(ua.id == 0)
                    return _return(
                        controller->createResponse(Status::CODE_500, "Login first.");
                    );

                Status status = Status::CODE_200;
                String errmsg;
                if(!nad || !nad->article)
                {
                    errmsg = mkErrMsg("Body json no data");
                    auto response = controller->createResponse(Status::CODE_400, errmsg);
                    response->putHeaderIfNotExists("Content-Type", "application/json");

                    return _return(response);
                };

                if(
                    nad->article->title->length() < 2 ||
                    nad->article->body->length() < 2 ||
                    nad->article->description->length() < 2
                )
                {
                    errmsg = mkErrMsg("Title/Description/Body can not be too short");
                    auto response = controller->createResponse(Status::CODE_400, errmsg);
                    response->putHeaderIfNotExists("Content-Type", "application/json");
                    return _return(response);
                };

                auto ard = controller->m_articleService.newArticle(nad->article, ua.id);

                return _return(controller->createDtoResponse(Status::CODE_200, ard));
            };
        };


        ENDPOINT_ASYNC("PUT", "/api/articles/{slug}", UpdateArticle)
        {
            ENDPOINT_ASYNC_INIT(UpdateArticle)
            Action act() override 
            {
                return request->readBodyToDtoAsync<oatpp::Object<UpdateArticleDto>>
                (
                    controller->getDefaultObjectMapper()
                ).callbackTo(&updateArticle::act1);
            }

            Action act1( const oatpp::Object<UpdateArticleDto>& nad)
            {
                auto ua = UserAuth::fromAuthHeader(request);
                if( ua.id == 0 )
                {
                    return _return(controller->createResponse( Status::CODE_500, "Login first" ));
                };
                Status status = Status::CODE_200;
                String errmsg;
                if(!nad || !nad->article)
                {
                    errmsg = mkErrMsg("body json no data");
                    auto response = controller->createResponse( Status::CODE_400, errmsg );
                    response->putHeaderIfNotExists("Content-Type", "application/json");

                    return _return(response);
                };

                if(
                    nad->article->title->length() < 2 ||
                    nad->article->body->length() < 2 ||
                    nad->article->description->length() < 2 ||
                )
                {
                    errmsg = mkErrMsg("Title/Description/Body can not be too short.");
                    auto response = controller->createResponse( Status::CODE_400, errmsg );
                    response->putHeaderIfNotExists("Content-Type", "application/json");
                    
                    return _return(response);
                }

                auto ard = controller->m_articleService.updateArticle( nad->article, ua.id );
                return _return(controller->createDtoResponse(Status::CODE_200, ard));
            }
        };

        ENDPOINT_ASYNC("DELETE", "/api/articles/{slug}", DeleteArticle)
        {
            ENDPOINT_ASYNC_INIT(DeleteArticle)
            Action act() override
            {
                auto ua = UserAuth::fromAuthHeader(request);
                if(ua.id == 0)
                {
                    return _return(controller->createResponse( Status::CODE_500, "Login first" ));
                };

                String slug = request->getPathVariable("slug");
                auto ard = controller->m_articleService.deleteArticle(slug, ua.id);

                auto response = controller->createResponse( Status::CODE_200, ard );
                return _return(response);
            }
        };

        
        ENDPOINT_ASYNC("GET", "/api/articles", GetArticles)
        {
            ENDPOINT_ASYNC_INIT(GetArticles)
            Action act() override
            {
                UInt32 offset, limit;
                auto ua = UserAuth::fromAuthHeader(request);
                if(ua.id == 0)
                {
                    return _return(controller->createResponse( Status::CODE_500, "Login first" ));
                }

                auto s_offset = request->getQueryParameter("offset");
                (s_offset) ? offset = atoi(s_offset->c_str()) : offset = (v_uint32)0;

                auto s_limit = request->getQueryParameter("limit");
                (s_limit) ? s_limit = atoi(s_limit->c_str()) : limit = PAGE_LIMIT;

                oatpp::Object<ArticleResultDto> ard;
                auto s_tag = request->getQueryParameter("tag");
                auto s_favorited = request->getQueryParameter("favorited");
                auto s_author = request->getQueryParameter("author");

                if(s_tag)
                {
                    s_tag = urlDecode(s_tag).c_str();
                    ard = controller->m_articleService.getAllByTag(s_tag, ua.id, offset, limit);
                }
                else if(s_author)
                {
                    s_author = urlDecode(s_author).c_str();
                    ard = controller->m_articleService.getAllByAuthor(s_author, ua.id, offset, limit);
                }
                else if(s_favorited)
                {
                    s_favorited = urlDecode(s_favorited).c_str();
                    ard = controller->m_articleService.getAllByFavorited(s_favorited, ua.id, offset, limit);
                }
                else
                {
                    ard = controller->m_articleService.getAll(ua.id, offset, limit);
                }

                return _return(controller->createDtoResponse( Status::CODE_200, ard ));
            };
        };

        ENDPOINT_ASYNC("GET", "/api/tags", GetTags)
        {
            ENDPOINT_ASYNC_INIT(GetTags)
            Action act() override
            {
                auto trd = controller->m_articleService.getTags();
                return _return(controller->createDtoResponse( Status::CODE_200, trd ));
            };
        };

        ENDPOINT_ASYNC("POST", "/api/articles/{slug}/favorite", Favorite)
        {
            ENDPOINT_ASYNC_INIT(Favorite)
            Action act() override
            {
                auto ua = UserAuth::fromAuthHeader(request);

                if(ua.id == 0)
                {
                    return _return(
                        controller->createResponse( Status::CODE_500, "Login first" )
                    );
                }

                String slug = request->getPathVariable("slug");
                auto frd = controller->m_articleService.favorite(slug, ua.id);

                return _return(controller->createDtoResponse( Status::CODE_200, frd ));
            };
        };

        ENDPOINT_ASYNC("DELETE", "/api/articles/{slug}/favorite", UnFavorite)
        {
            ENDPOINT_ASYNC_INIT(UnFavorite)
            Action act() override
            {
                auto ua = UserAuth::fromAuthHeader(request);

                if(ua.id == 0)
                {
                    return _return(
                        controller->createResponse( Status::CODE_500, "Login first" )
                    );
                };

                String slug = request->getPathVariable("slug");
                auto frd = controller->m_articleService.unFavorite(slug, ua.id);
                
                return _return(
                    controller->createDtoResponse( Status::CODE_200, frd )
                );
            }
        };

        ENDPOINT_ASYNC("GET", "/api/articles/feed", GetArticlesFeed)
        {
            ENDPOINT_ASYNC_INIT(GetArticlesFeed)
            Action act() override
            {
                UInt32 offset, limit;
                auto ua = UserAuth::fromAuthHeader(request);

                if(ua.id == 0)
                {
                    return _return(
                        controller->createResponse( Status::CODE_500, "Login first")
                    );
                };

                auto s_offset = request->getQueryParameter("offset");
                (s_offset) ? offset = atoi(s_offset->c_str()) : offset = (v_uint32)0;

                auto s_limit = request->getQueryParameter("limit");
                (s_limit) ? limit = atoi(s_limit->c_str()) : limit = PAGE_LIMIT;

                auto ard = controller->m_articleService->getFeed( ua.id, offset, limit );
                return _return(
                    controller->createDtoResponse( Status::CODE_200, ard )
                );
            };
        };

        ENDPOINT_ASYNC("GET", "/api/articles/{slug}", GetArticle)
        {
            ENDPOINT_ASYNC_INIT(GetArticle)
            Action act() override
            {
                auto ua = UserAuth::fromAuthHeader(request);
                if(ua.id == 0 && !controller->config->publicMode)
                {
                    return _return(
                        controller->createResponse( Status::CODE_500, "Login first" )
                    );
                };

                auto slug = request->getPathVariable("slug");
                auto ard = controller->m_articleService.getOne( slug, ua.id );
                
                return _return(controller->createDtoResponse( Status::CODE_200, ard ));
            };
        };

};

#include OATPP_CODEGEN_BEGIN(ApiController)