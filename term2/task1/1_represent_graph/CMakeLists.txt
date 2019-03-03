cmake_minimum_required(VERSION 3.12)
project(1_make_graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_make_graph main.cpp graph.h MatrixGraph.cpp MatrixGraph.h dfs.cpp dfs.h SetGraph.cpp SetGraph.h ArcGraph.cpp ArcGraph.h list_graph.cpp list_graph.h)