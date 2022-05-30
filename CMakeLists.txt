cmake_minimum_required(VERSION 3.20)
project(DA-2.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(Tests)

add_executable(DA-2.0
        Tests/ReadFile.cpp
        Tests/graph.cpp
        main.cpp Tests/Cenario1_2.cpp Tests/Cenarip1_2.h)
