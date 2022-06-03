//
// Created by Michał on 13.03.2022.
//

#include <iostream>
#include "MyArrayEdge.h"
#include "../FileManagement.h"


void MyArrayEdge::addRear(Edge element) {
//creating a new functionManager, rewriting each element with pointers and adding last element
    size++;
    Edge *newTab = new Edge[size];
    Edge *toDelete = tabPointer;

    if (size > 0) {
        Edge *tempPointer = newTab;
        for (int i = 0; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
    }
    newTab[size - 1] = element;

    tabPointer = newTab;
    delete toDelete;
}

void MyArrayEdge::addFront(Edge element) {
    //creating a new functionManager, adding new first element and rewriting each element with pointers until the end
    size++;
    Edge *newTab = new Edge[size];
    Edge *toDelete = tabPointer;

    if (size > 1) {
        Edge *tempPointer = newTab;
        tempPointer++;
        for (int i = 0; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
    }
    newTab[0] = element;

    tabPointer = newTab;
    delete toDelete;
}

void MyArrayEdge::addOnPos(int position, Edge container) {
//creating a new functionManager, rewriting each element until certain position, then inserting extra one and rewriting until the end

    if (position == 0) {
        addFront(container);
        return;
    }
    if (position == size - 1) {
        addRear(container);
        return;
    }

    if ((position < size - 1) && (position > 0)) {
        size++;
        Edge *newTab = new Edge[size];
        Edge *toDelete = tabPointer;

        Edge *tempPointer = newTab;
        for (int i = 0; i < position; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        *tempPointer = container;
        tempPointer++;

        for (int i = position; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete toDelete;
    }
}

void MyArrayEdge::deleteRear() {
    //creating a new functionManager, rewriting each element but the last one
    if (size > 0) {
        size--;
        Edge *newTab = new Edge[size];
        Edge *toDelete = tabPointer;
        Edge *tempPointer = newTab;

        for (int i = 0; i < size; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete[] toDelete;
    }
}

void MyArrayEdge::deleteFront() {
//creating a new functionManager, skipping first one, and rewriting each element with pointers
    if (size > 0) {
        size--;
        Edge *newTab = new Edge[size];
        Edge *toDelete = tabPointer;
        Edge *tempPointer = newTab;
        tabPointer++;
        for (int i = 0; i < size; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
        tabPointer = newTab;
        delete[] toDelete;
    }
}

void MyArrayEdge::deleteOnPos(int position) {
//creating a new functionManager, rewriting each element until certain position, then skipping one position and rewriting until the end
    if ((position < size) && (position > -1)) {
        Edge *newTab = new Edge[size - 1];
        Edge *toDelete = tabPointer;
        Edge *tempPointer = newTab;
        for (int i = 0; i < position; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer++;

        for (int i = position; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete[] toDelete;
        size--;
    }

}

void MyArrayEdge::swap(int pos1, int pos2) {
    //copying elements from both positions and pasting them on swapped positions
    if ((pos1 > -1) && (pos1 < size)) {
        if ((pos2 > -1) && (pos2 < size)) {
            Edge *pos1Ptr = tabPointer + pos1;
            Edge *pos2Ptr = tabPointer + pos2;
            Edge temp = *pos1Ptr;
            *pos1Ptr = *pos2Ptr;
            *pos2Ptr = temp;

        }
    }

}

int MyArrayEdge::findFirst(int value) {
//inspecting every element until finding correct one
    Edge *tempPointer = tabPointer;
    for (int i = 0; i < size; i++) {
        if ((tempPointer + i)->weight == value)
            return i;
    }
    return -1;//returning -1 if there is no such element
}

Edge MyArrayEdge::get(int position) {
    return *(tabPointer + position);
}

int MyArrayEdge::getSize() {
    return size;
}

void MyArrayEdge::show() {
    //inspecting and writing every element
    Edge *tempPointer = tabPointer;

    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << tempPointer->weight << " ";
        tempPointer++;
    }
    std::cout << std::endl;
}

void MyArrayEdge::deleteAll() {
    //deleting entire container
    if (tabPointer != nullptr)
        delete[] tabPointer;
}
