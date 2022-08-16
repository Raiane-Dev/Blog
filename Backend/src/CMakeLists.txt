# cmake_minimum_required(VERSION 3.4.1)

# project(main)

# # include_directories(
#     # ./libraries/vcpkg_installed/x64-linux/share/poco
# # )

# # LINK_DIRECTORIES(
# #     ./libraries/vcpkg_installed/x64-linux/lib
# # )
# add_library(math SHARED ./libraries/vcpkg_installed/x64-linux/include/Poco)

# # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# find_package(Poco CONFIG REQUIRED)
# # find_package(Poco Foundation Net XML Zip Data JSON)

# target_link_libraries(main PRIVATE Poco::Net Poco::XML Poco::Zip Poco::Data)
    # this is heuristically generated, and may not be correct
#    find_package(Poco CONFIG REQUIRED)
    # note: 9 additional targets are not displayed.
#    target_link_libraries(main PRIVATE Poco::Net Poco::XML Poco::Zip Poco::Data)
# add_executable(main src/Server.cpp)


cmake_minimum_required(VERSION 3.13.4)

project(Application)

set(CMAKE_PREFIX_PATH /app/libraries/vcpkg_installed/x64-linux)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /app/build/bin)

find_package(Poco REQUIRED Foundation Net XML Zip Data JSON Util)

add_executable(
    main app/Server.cpp
)

target_link_libraries(
    main
    PRIVATE Poco::Foundation Poco::Util Poco::Net
)