#include <iostream>
#include "Graph/Graph.h"

int main() {
    Graph * temp = new Graph();

    temp->addNode();
    temp->addNode();
    temp->addNode();
    temp->addNode();

    temp->addEdge(0, 2, 5);

    temp->show();
}
