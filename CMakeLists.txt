cmake_minimum_required(VERSION 3.21)
project(Proj2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proj2 main.cpp FileManagement.cpp FileManagement.h Graph/Graph.cpp Graph/Graph.h PrimMST.cpp PrimMST.h)
