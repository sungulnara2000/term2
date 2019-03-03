cmake_minimum_required(VERSION 3.12)
project(helper)

set(CMAKE_CXX_STANDARD 14)

add_executable(strongly_connected main.cpp findSCC.cpp list_graph.cpp list_graph.h graph.h getTranspose.cpp CountAddEdges.cpp)
