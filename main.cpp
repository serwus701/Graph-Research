#include <iostream>
#include "BinaryHeap/MyBinaryHeapEdge.h"
#include "Graph/MatrixGraph.h"
#include "Algorithms.h"

int main() {
    MatrixGraph * graph = new MatrixGraph();


    MyArrayEdge * listaKrawedzi = new MyArrayEdge();
    listaKrawedzi->addFront(Edge(0, 2, 1));
    //listaKrawedzi->addFront(Edge(0, 3, 1));
    //listaKrawedzi->addFront(Edge(2, 3, 1));
    //listaKrawedzi->addFront(Edge(1, 3, 1));

    std::cout<<std::endl<<(new Algorithms())->doesMakeCycle(listaKrawedzi, Edge(0, 1, 1))<<std::endl;


}
