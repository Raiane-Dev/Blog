cmake_minimum_required(VERSION 3.13.4)

project(Application)

set(CMAKE_PREFIX_PATH /app/libraries/vcpkg_installed/x64-linux)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /app/build/bin)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# option(RUN_PROD "Prod?" OFF)

# add_definitions(
#     -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/database.json"
# )

add_library( 
    ${PROJECT_NAME}-lib
    /app/src/includes/config/Database.hpp
)
target_include_directories(${project_name}-lib
    PUBLIC /app/src/includes
)

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-postgresql 1.3.0 REQUIRED)

add_executable(
    ${PROJECT_NAME}
    app/Server.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE oatpp::oatpp 
    PRIVATE oatpp::oatpp-postgresql
)
