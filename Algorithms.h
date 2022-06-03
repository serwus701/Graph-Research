//
// Created by Michał on 01.06.2022.
//

#ifndef MAIN_CPP_ALGORITHMS_H
#define MAIN_CPP_ALGORITHMS_H


#include "Graph/MatrixGraph.h"
#include "Array/MyArrayEdge.h"
#include "Graph/ListGraph.h"

class Algorithms {
    static int getCheapestEdge(MyArrayEdge *, MyArrayEdge *);
    //static bool doesMakeCycle(MyArrayEdge *, Edge);

public:
    static MatrixGraph primMST(MatrixGraph);
    static MatrixGraph kruskalMST(MatrixGraph);
    static int * djikstra(MatrixGraph);
    static int * fordBellman(MatrixGraph);

    static MatrixGraph primMST(ListGraph);
    static MatrixGraph kruskalMST(ListGraph);
    static int * djikstra(ListGraph);
    static int * fordBellman(ListGraph);
    static bool isGraphConnected(MatrixGraph);

    static bool doesMakeCycle(MyArrayEdge *, Edge);
};


#endif //MAIN_CPP_ALGORITHMS_H
