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

# link_directories(/usr/lib)
# include_directories(/usr/include)

include_directories(HEADER_FILES /app/src/includes)

find_package(PkgConfig)
find_package(Boost REQUIRED COMPONENTS system)
find_package(plog CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_library(PQ_LIB pq)
find_package(libpqxx CONFIG REQUIRED)

pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(
    ${PROJECT_NAME}
    includes/config/Connect.hpp 
    app/config/Connect.cpp
    
    includes/config/Logger.hpp 
    app/config/Logger.cpp 
    
    includes/utils/CommandQuery.hpp
    app/utils/CommandQuery.cpp

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
)