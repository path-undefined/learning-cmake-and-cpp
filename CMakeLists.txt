cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE "./app/*.cpp")

add_executable(HelloWorld ${SOURCE})
target_include_directories(HelloWorld PRIVATE ".")
