cmake_minimum_required(VERSION 3.12)
project(shortest_paths)

set(CMAKE_CXX_STANDARD 14)

add_executable(shortest_paths main.cpp SetGraph.cpp SetGraph.h graph.h bfs.cpp bfs.h)