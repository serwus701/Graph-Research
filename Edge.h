//
// Created by Michał on 01.06.2022.
//

#ifndef MAIN_CPP_EDGE_H
#define MAIN_CPP_EDGE_H


#pragma once

#include <cstdlib>

struct Edge{
    size_t origin;
    size_t destination;
    size_t weight;

    Edge(){
        this->origin = -1;
        this->destination = -1;
        this->weight = -1;
    }

    Edge(const size_t &originVertex, const size_t &destVertex, const size_t &weight){
        this->origin = originVertex;
        this->destination = destVertex;
        this->weight = weight;
    }

    bool operator < ( const Edge & edge ) const
    {
        if( this->weight < edge.weight )
            return true;
        else
            return false;
    }

    bool operator > ( const Edge & edge ) const
    {
        if( this->weight > edge.weight )
            return true;
        else
            return false;
    }

};


#endif //MAIN_CPP_EDGE_H
