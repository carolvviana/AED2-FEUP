cmake_minimum_required(VERSION 3.23)
project(AEDP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDP2
        main.cpp
        Coordinate.cpp
        Coordinate.h
        Data.cpp
        Data.h
        Interface.cpp
        Interface.h)
