#include "queue.h"

qNode::qNode(edge pathin, float weight) : path(pathin), nextNode(NULL), weight(weight) {}

edge qNode::getPath(){
    return path;
}

void qNode::setPath(qNode *in){
    nextNode = in;
}

float qNode::getWeight(){
    return weight;
}

pQueue::pQueue() : head(NULL) {}

qNode pQueue::getHead(){
    return *head;
}
void pQueue::insert(edge newPath, float weight){
    qNode newNode(newPath, weight);
    qNode *curr = head;
    while(weight > curr->nextNode->getWeight()){

    }
}
qNode pop();
