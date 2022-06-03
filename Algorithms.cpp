//
// Created by Michał on 01.06.2022.
//


#include "Algorithms.h"
#include "BinaryHeap/MyBinaryHeapEdge.h"
#include "Array/MyArray.h"

MatrixGraph Algorithms::primMST(MatrixGraph graph) {
    if (graph.getSize() > 0 && isGraphConnected(graph)) {
        MyArray *nodes = new MyArray();
        MyArrayEdge *usedEdges = new MyArrayEdge();

        int nodesCounter = 1;
        nodes->addFront(0);
        while (nodesCounter < graph.getSize()) {
            MyArrayEdge *possibleEdges = new MyArrayEdge();
            for (int i = 0; i < nodes->getSize(); ++i) {
                for (int j = 0; j < graph.getSize(); ++j) {
                    if (graph.getTabPointer()[i][j] != 0) {
                        possibleEdges->addFront(Edge(i, j, graph.getTabPointer()[i][j]));
                    }
                }
            }
            usedEdges->addFront(possibleEdges->get(getCheapestEdge(possibleEdges, usedEdges)));
        }
    }


    return MatrixGraph();
}

MatrixGraph Algorithms::kruskalMST(MatrixGraph) {
    return MatrixGraph();
}

int *Algorithms::djikstra(MatrixGraph) {
    return nullptr;
}

int *Algorithms::fordBellman(MatrixGraph) {
    return nullptr;
}

MatrixGraph Algorithms::primMST(ListGraph) {
    return MatrixGraph();
}

MatrixGraph Algorithms::kruskalMST(ListGraph) {
    return MatrixGraph();
}

int *Algorithms::djikstra(ListGraph) {
    return nullptr;
}

int *Algorithms::fordBellman(ListGraph) {
    return nullptr;
}

bool Algorithms::isGraphConnected(MatrixGraph graph) {
    for (int i = 0; i < graph.getSize(); i++) {
        bool hasFound = false;
        for (int j = 0; j < graph.getSize(); j++) {
            if (graph.getTabPointer()[i][j] != 0)
                hasFound = true;
            if (graph.getTabPointer()[j][i] != 0)
                hasFound = true;
        }
        if (!hasFound)
            return false;
    }
    return true;
}

int Algorithms::getCheapestEdge(MyArrayEdge *myArrayEdge, MyArrayEdge *usedEdges) {
    int min = SIZE_MAX;
    if (myArrayEdge->getSize() == 0)
        return 0;
    for (int i = 0; i < myArrayEdge->getSize(); ++i) {
        bool alreadyUsed = false;
        for (int j = 0; j < usedEdges->getSize(); ++j) {
            if (usedEdges->get(j).origin == myArrayEdge->get(i).origin)
                if (usedEdges->get(j).destination == myArrayEdge->get(i).destination) {
                    alreadyUsed = true;
                    break;
                }
        }
        if (myArrayEdge->get(i).weight < min && !alreadyUsed)
            min = myArrayEdge->get(i).weight;
    }
    return min;
}

bool Algorithms::doesMakeCycle(MyArrayEdge *myArrayEdge, Edge edge) {
    MyArray *nodes = new MyArray();
    for (int i = 0; i < myArrayEdge->getSize(); ++i) {
        bool originNodeAlreadyAdded = false;
        bool destinationNodeAlreadyAdded = false;
        for (int j = 0; j < nodes->getSize(); ++j) {
            if (nodes->get(j) == myArrayEdge->get(i).origin)
                originNodeAlreadyAdded = true;
            if (nodes->get(j) == myArrayEdge->get(i).destination)
                originNodeAlreadyAdded = true;
        }
        if (!originNodeAlreadyAdded)
            nodes->addFront(myArrayEdge->get(i).origin);
        if (!destinationNodeAlreadyAdded)
            nodes->addFront(myArrayEdge->get(i).destination);

    }
    bool originNodeAlreadyHappened = false;
    bool destinationNodeAlreadyHappened = false;
    for (int i = 0; i < nodes->getSize(); ++i) {
        if(edge.destination == nodes->get(i))
            destinationNodeAlreadyHappened = true;
        if(edge.origin == nodes->get(i))
            originNodeAlreadyHappened = true;
    }
    if(originNodeAlreadyHappened||destinationNodeAlreadyHappened)
        return true;
    else
        return false;

}
