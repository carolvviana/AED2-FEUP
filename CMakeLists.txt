cmake_minimum_required(VERSION 3.23)
project(AEDP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDP2
        main.cpp
        Coordinate.cpp
        Coordinate.h
        City.cpp
        City.h
        Airline.cpp
        Airline.h
        Airport.cpp
        Airport.h
        Data.cpp
        Data.h
        Graph.cpp
        Graph.h
        )
