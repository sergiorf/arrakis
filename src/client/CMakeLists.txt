cmake_minimum_required(VERSION 3.2)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(arrakis-client)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "arrakis-client")

set(INCROOT ${PROJECT_SOURCE_DIR})
set(SRCROOT ${PROJECT_SOURCE_DIR})

set(SRC
    ${SRCROOT}/main.cpp
    ${SRCROOT}/Game.cpp
    ${INCROOT}/Game.hpp
    ${INCROOT}/TextureManager.cpp
    ${INCROOT}/TextureManager.hpp
    ${INCROOT}/Tile.cpp
    ${INCROOT}/Tile.hpp
    ${INCROOT}/AnimationHandler.cpp
    ${INCROOT}/AnimationHandler.hpp
    ${INCROOT}/GameState.hpp
    ${INCROOT}/Gui.cpp
    ${INCROOT}/Gui.hpp
    ${INCROOT}/GameStateStart.cpp
    ${INCROOT}/GameStateStart.hpp
    ${INCROOT}/GameStateEditor.cpp
    ${INCROOT}/GameStateEditor.hpp
    ${INCROOT}/Map.cpp
    ${INCROOT}/Map.hpp
    ${INCROOT}/City.cpp
    ${INCROOT}/City.hpp
)
source_group("" FILES ${SRC})

add_executable(${EXECUTABLE_NAME} ${SRC})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE sfml-graphics)
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)
if (WIN32)
  set_target_properties(${EXECUTABLE_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
endif()
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${EXECUTABLE_NAME}> $<TARGET_FILE_DIR:${EXECUTABLE_NAME}> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ${EXECUTABLE_NAME})

# Install executable
install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION .)

# Install game assets
install(DIRECTORY media/ DESTINATION media/)
		
# Install config files
install(FILES city_cfg.dat city_map.dat LICENSE README.md DESTINATION .)


# Install
install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${PROJECT_BINARY_DIR}/build)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/media DESTINATION ${PROJECT_BINARY_DIR}/build)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

