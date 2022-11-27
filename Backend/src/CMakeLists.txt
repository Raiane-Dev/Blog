cmake_minimum_required(VERSION 3.13.4)

project(Application)

set(CMAKE_PREFIX_PATH /app/libraries/vcpkg_installed/x64-linux)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /app/build/bin)
option(RUN_PROD "Prod?" OFF)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE static)
set(VCPKG_CMAKE_SYSTEM_NAME Linux)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# link_directories(/usr/lib)
# include_directories(/usr/include)

include_directories(HEADER_FILES /app/src/includes)

find_package(PkgConfig)
find_package(Boost REQUIRED COMPONENTS system)
find_package(plog CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_library(PQ_LIB pq)
find_package(libpqxx CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_path(JWT_CPP_INCLUDE_DIRS "jwt-cpp/base.h")

pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(
    ${PROJECT_NAME}
    app/config/Connect.cpp

    app/config/Logger.cpp 
    
    app/utils/Queries.cpp

    app/middleware/Authentication.cpp

    app/utils/Tratament.cpp

    app/models/ArticleModel.cpp

    app/controllers/ArticleController.cpp

    app/routes/Marker.cpp

    app/Server.cpp
)

include_directories(
    ${PROJECT_NAME} PRIVATE includes/config
)
# add_library(
#     ${PROJECT_NAME}-libs SHARED 
#     app/config/Connect.cpp
# )

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC OpenSSL::SSL OpenSSL::Crypto
    PRIVATE plog::plog
    PRIVATE pq
    PRIVATE libpqxx::pqxx
    PRIVATE PkgConfig::Pistache
    PRIVATE fmt::fmt-header-only
    PRIVATE ${JWT_CPP_INCLUDE_DIRS}
)