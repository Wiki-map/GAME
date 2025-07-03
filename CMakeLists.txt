cmake_minimum_required(VERSION 3.10.0)
project(GAME VERSION 0.1.0 LANGUAGES C CXX)

option(PRODUCTION_BUILD "Make this a production build" OFF)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE MY_SOURCES CONFIG_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_subdirectory("${CMAKE_SOURCE_DIR}\\third_party\\raylib")
add_subdirectory("${CMAKE_SOURCE_DIR}\\third_party\\json")
add_subdirectory("${CMAKE_SOURCE_DIR}\\third_party\\rlImGui")
add_subdirectory("${CMAKE_SOURCE_DIR}\\third_party\\imgui-docking")

add_executable(GAME "${MY_SOURCES}")

if(PRODUCTION_BUILD)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCE_PATH="assets/")
else()
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
endif()

target_include_directories(GAME PRIVATE "${CMAKE_SOURCE_DIR}/include/")
target_link_libraries(GAME raylib_static nlohmann_json::nlohmann_json rlimgui imgui)

if(PRODUCTION_BUILD)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()