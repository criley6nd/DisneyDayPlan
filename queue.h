#include <iostream>
#include "edge.h"

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

class pQueue{
    private:
        qNode *head;
    public:
        pQueue();
        qNode *getHead();
        void insert(edge newNode, float weight);
        qNode pop();

};