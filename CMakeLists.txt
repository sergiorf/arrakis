cmake_minimum_required(VERSION 3.2)

project(arrakis)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src/client)
add_subdirectory(src/server)
