cmake_minimum_required(VERSION 3.17)
project(JsonTestcase)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -pedantic -Werror -fno-exceptions -Wno-unknown-pragmas)
add_definitions(-D_HAS_EXCEPTIONS=0)

include_directories(${PROJECT_SOURCE_DIR}/ThirdParty/nlohmann_json/include)

add_executable(JsonTestcase main.cpp)
