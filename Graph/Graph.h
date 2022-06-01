//
// Created by Michał on 01.06.2022.
//

#ifndef PROJ2_GRAPH_H
#define PROJ2_GRAPH_H


class Graph {
    int size;
    int **tabPointer;


public:
    Graph();

    void addNode();

    void show();

    void addEdge(int ,int, int);

};


#endif //PROJ2_GRAPH_H
