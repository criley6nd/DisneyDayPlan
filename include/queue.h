#include <iostream>
#include "edge.h"
#ifndef QNODE_H
#define QNODE_H

//class for a node in the priorety queue
//contains an edge and a weight of the edge
//in the queue
class qNode{
    private:
        edge path;
        float weight;
    public:
        qNode *nextNode;
        qNode(edge pathin, float weightin);
        edge getPath();
        float getWeight();
        void setPath(qNode *in);


};
#endif

#ifndef PQUEUE_H
#define PQUEUE_H

//class for a priorety queue
//contains a head node and ways to get the node
//remove the node and add to the queue
//queue sorts from least to greatest where head is
//the least
class pQueue{
    private:
        qNode *head;
    public:
        pQueue();
        ~pQueue();
        pQueue(const pQueue&);
        pQueue& operator=(const pQueue& assign);
        qNode *getHead();
        void insert(edge newNode, float weight);
        qNode pop();

};

#endif