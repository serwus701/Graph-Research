//
// Created by Michał on 13.03.2022.
//

#ifndef MAIN_CPP_MYARRAYEDGE_H
#define MAIN_CPP_MYARRAYEDGE_H


#include "../Edge.h"

class MyArrayEdge {
private:
    int size = 0;
    Edge *tabPointer = nullptr;
public:
    void addFront(Edge);

    void addRear(Edge);

    void addOnPos(int, Edge);

    void deleteFront();

    void deleteRear();

    void deleteOnPos(int);

    void swap(int, int);//swapping elements in two given positions

    int findFirst(int);//returns position of first element with equal to given value

    int getSize();//returns size of structure

    Edge get(int);//returns element at the given position

    void show();

    void deleteAll();//delete structure
};


#endif //MAIN_CPP_MYARRAYEDGE_H
