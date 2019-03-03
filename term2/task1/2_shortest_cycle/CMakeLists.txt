cmake_minimum_required(VERSION 3.12)
project(2_shortest_cycle)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_shortest_cycle main.cpp vertexCycle.cpp vertexCycle.h SetGraph.cpp SetGraph.h graph.h shortestCycle.cpp)