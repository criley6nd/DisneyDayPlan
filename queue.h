#include <iostream>
#include "edge.h"
#ifndef QNODE_H
#define QNODE_H

class qNode{
    private:
        edge path;
        float weight;
    public:
        qNode *nextNode;
        qNode(edge pathin, float weight);
        edge getPath();
        float getWeight();
        void setPath(qNode *in);


};
#endif

#ifndef PQUEUE_H
#define PQUEUE_H

class pQueue{
    private:
        qNode *head;
    public:
        pQueue();
        ~pQueue();
        qNode *getHead();
        void insert(edge newNode, float weight);
        qNode pop();

};

#endif