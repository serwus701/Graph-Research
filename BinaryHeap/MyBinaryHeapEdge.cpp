//
// Created by serwu on 14.04.2022.
//

#include <iostream>
#include <valarray>
#include "MyBinaryHeapEdge.h"
#include "../FileManagement.h"

void MyBinaryHeapEdge::deleteLast() {
    if (size > 0) {
        body->deleteRear();
        size--;
    }
}

void MyBinaryHeapEdge::add(Edge container) {
    body->addRear(container);
    size++;
}

void MyBinaryHeapEdge::deleteRoot() {
    if (size > 0) {
        body->deleteFront();
        size--;
    }
}

void MyBinaryHeapEdge::regainHeapAttributes() {
    //iterates trough array until making no change
    //when function finds bigger than it's father it replaces them
    //when both sons are bigger than father function chooses bigger son to change with father

    if (size > 3) {
        for (int i = size / 2; i >= 0; --i) {
            heapify(i);
        }
    } else {
        int max = INT16_MIN;
        int pos = 0;
        for (int i = 0; i < size; i++) {
            if (body->get(i).weight > max) {
                max = body->get(i).weight;
                pos = i;
            }
            if (pos > 0)
                body->swap(0, pos);
        }
    }
}

void MyBinaryHeapEdge::show() {
    //simple show function with extra endlines to simulate binary heap appearance
    //body->show();

    if (size > 3) {
        std::cout << std::endl;
        int depth = getDepth();
        int spaces = 1;

        for (int i = 0; i < depth - 1; i++) {
            spaces *= 2;
            spaces++;
        }

        int powersOfTwo = 1;
        int i = 0;
        while (i < depth) {
            std::cout << std::string(spaces / 2, ' ');
            for (int j = 0; j < powersOfTwo; j++) {
                std::cout << body->get(i).weight << std::string(spaces, ' ');
                i++;
            }

            spaces--;
            spaces = spaces / 2;

            powersOfTwo *= 2;
            std::cout << std::endl;
        }
        for (; i < size; i++) {
            std::cout << body->get(i).weight << " ";
        }
        std::cout << std::endl;
    } else if (size > 0) {
        std::cout << " " << body->get(0).weight << "\n";
        for (int i = 1; i < size; i++)
            std::cout << body->get(i).weight << " ";
        std::cout << std::endl;
    }
}

int MyBinaryHeapEdge::findFirst(int number) {
    return body->findFirst(number);
}

void MyBinaryHeapEdge::deleteAll() {
    body->deleteAll();
    size = 0;
}

int MyBinaryHeapEdge::getDepth() {
    int powersOfTwo = 1;
    int counter = 0;
    int i = 0;

    while (i <= size) {
        counter++;
        i += powersOfTwo;
        powersOfTwo *= 2;
    }

    return counter;
}

void MyBinaryHeapEdge::heapify(int position) {
    int left = 2 * position + 1;
    int right = 2 * position + 2;
    int smallestNum = position;

    if (left < size && body->get(left).weight < body->get(smallestNum).weight) {
        smallestNum = left;
    }

    if (right < size && body->get(right).weight < body->get(smallestNum).weight) {
        smallestNum = right;
    }

    if (smallestNum != position) {
        body->swap(smallestNum, position);

        heapify(smallestNum);
    }
}
