cmake_minimum_required(VERSION 3.20)
project(DA-2.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(../../DA-2.0-master/Tests)

add_executable(DA-2.0
        Tests/graph.cpp
        Tests/Paths.cpp
        Tests/ReadFile.cpp
        Tests/Cenarios.cpp
        main.cpp)
