cmake_minimum_required(VERSION 3.12)
project(4_bipartite)

set(CMAKE_CXX_STANDARD 14)

add_executable(4_bipartite main.cpp SetGraph.cpp SetGraph.h graph.h isBipartite.cpp)