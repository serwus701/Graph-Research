//
// Created by Michał on 01.06.2022.
//

#ifndef PROJ2_GRAPH_H
#define PROJ2_GRAPH_H


class MatrixGraph {
    int size;
    int **tabPointer;


public:
    MatrixGraph();

    void addNode();

    void show();

    void addEdge(int ,int, int);

    int getSize();

    int ** getTabPointer();

};


#endif //PROJ2_GRAPH_H
