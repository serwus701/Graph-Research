cmake_minimum_required(VERSION 3.21)
project(Proj2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proj2 main.cpp FileManagement.cpp FileManagement.h Graph/MatrixGraph.cpp Graph/MatrixGraph.h Algorithms.cpp Algorithms.h Array/MyArrayEdge.cpp Array/MyArrayEdge.h BinaryHeap/MyBinaryHeapEdge.cpp BinaryHeap/MyBinaryHeapEdge.h Graph/ListGraph.cpp Graph/ListGraph.h Edge.h Array/MyArray.cpp Array/MyArray.h)
