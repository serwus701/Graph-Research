//
// Created by Michał on 01.06.2022.
//

#include <iostream>
#include "Graph.h"

void Graph::addNode() {
    int **newTab = new int *[size + 1];
    int **toDelete = tabPointer;

    for(int i = 0; i < size + 1; i++){
        newTab[i] = new int [size + 1];
    }

    if (size > 0) {//rewriting array
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                newTab[i][j] = tabPointer[i][j];
            }
        }
    }

    for (int i = 0; i < size + 1; i++) {//filling new fields
        newTab[size][i] = 0;
    }
    for (int i = 0; i < size; i++) {
        newTab[i][size] = 0;
    }
    tabPointer = newTab;
    size++;
    delete toDelete;
}

void Graph::show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout<<tabPointer[i][j] << " ";
        }
        std::cout<<"\n";
    }
}

Graph::Graph() {
    size = 0;
    tabPointer = nullptr;
}

void Graph::addEdge(int from, int to, int cost) {
    if(from < size && to < size){
        tabPointer[from][to] = cost;
    }
}
