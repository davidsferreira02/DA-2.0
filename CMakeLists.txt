cmake_minimum_required(VERSION 3.20)
project(DA-2.0)

set(CMAKE_CXX_STANDARD 14)




include_directories(Tests)

add_executable(DA-2.0
        Tests/ReadFile.cpp
        main.cpp)

