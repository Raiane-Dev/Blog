cmake_minimum_required(VERSION 3.13.4)

project(Application)

set(CMAKE_PREFIX_PATH /app/libraries/vcpkg_installed/x64-linux)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /app/build/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(RUN_PROD "Prod?" OFF)

add_definitions(
    -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/database.json"
)

find_package(oatpp 1.3.0 REQUIRED)
# find_package(oatpp-postgresql 1.3.0 REQUIRED)
# add_library(${PROJECT_NAME}-lib STATIC /app/src/app/routes/Marker.cpp)

add_executable(
    ${PROJECT_NAME}
    /app/src/includes/routes/Marker.hpp
    /app/src/app/routes/Marker.cpp

    app/Server.cpp
)


target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC oatpp::oatpp
    # PUBLIC ${PROJECT_NAME}-lib 
    # PRIVATE oatpp::oatpp-postgresql
)
