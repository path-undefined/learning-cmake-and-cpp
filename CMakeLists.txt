cmake_minimum_required(VERSION 3.13)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE "./app/*.cpp")

add_executable(HelloWorld ${SOURCE})

target_include_directories(HelloWorld PRIVATE ".")

target_include_directories(HelloWorld PRIVATE "./vendor/SDL2-2.30.5/include")
target_link_directories(HelloWorld PRIVATE "./vendor/SDL2-2.30.5/lib64")
target_link_libraries(HelloWorld PRIVATE "SDL2")
