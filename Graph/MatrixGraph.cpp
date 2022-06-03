//
// Created by Michał on 01.06.2022.
//

#include <iostream>
#include "MatrixGraph.h"

void MatrixGraph::addNode() {
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

void MatrixGraph::show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout<<tabPointer[i][j] << " ";
        }
        std::cout<<"\n";
    }
}

MatrixGraph::MatrixGraph() {
    size = 0;
    tabPointer = nullptr;
}

void MatrixGraph::addEdge(int from, int to, int cost) {
    if(from < size && to < size){
        tabPointer[from][to] = cost;
        tabPointer[to][from] = cost;//?????????????????
    }
}

int MatrixGraph::getSize() {
    return size;
}

int **MatrixGraph::getTabPointer() {
    return tabPointer;
}
