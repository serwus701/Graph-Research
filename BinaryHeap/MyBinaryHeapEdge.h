//
// Created by serwu on 14.04.2022.
//

#ifndef MAIN_CPP_MYBINARYHEAPEDGE_H
#define MAIN_CPP_MYBINARYHEAPEDGE_H

#include "../Array/MyArrayEdge.h"

class MyBinaryHeapEdge {
private:
    MyArrayEdge *body = new MyArrayEdge();
    int size = 0;

    int getDepth();//returns amount of hip levels (excluding last, incomplete one)

    void heapify(int);//recurrent algorithm used for regaining heap attributes

public:
    void add(Edge);

    void deleteLast();

    void deleteRoot();

    void regainHeapAttributes();//structure regains heap attributes

    void show();

    int findFirst(int);//returns position of first element with equal to given value

    void deleteAll();//delete structure
};


#endif //MAIN_CPP_MYBINARYHEAPEDGE_H
