#include "../include/queue.h"
#include <stdlib.h>

//qNode constructors and get/set functions
qNode::qNode(edge pathin, float weightin) : path(pathin), weight(weightin),  nextNode(NULL) {}


edge qNode::getPath(){
    return path;
}

void qNode::setPath(qNode *in){
    nextNode = in;
}

float qNode::getWeight(){
    return weight;
}

//pQueue constructors and destructor
pQueue::pQueue() : head(NULL) {}

pQueue::pQueue(const pQueue& assign) : head(assign.head) {}

pQueue::~pQueue(){
    qNode *curr = head;
    while(curr != NULL){
        head = curr->nextNode;
        free(curr);
        curr = head;
    }
}

pQueue& pQueue::operator=(const pQueue& assign){
    if(this == &assign){
        this->head = assign.head;
    }
    return *this;

}

qNode *pQueue::getHead(){
    return head;
}

//inserts a node into the queue in sorted order by weight from 
//least to greatest
void pQueue::insert(edge newPath, float weight){
    qNode *newNode = new qNode(newPath, weight);
    if(head == NULL){
        head = newNode;
        return;
    }
    if(weight < head->getWeight()){
        newNode->nextNode = head;
        head = newNode;
        return;
    }
    if(head->nextNode == NULL){
        if(weight > head->getWeight()){
            head->nextNode = newNode;
            newNode->nextNode = NULL;
        }
        else{
            newNode->nextNode = head;
            head = newNode;
        }
        return;
    }
    qNode *next = head->nextNode;
    qNode *curr = head;
    while(weight > next->getWeight()){
        curr = next;
        next = next->nextNode;
        if(next == NULL){break;}

    }
    
    newNode->nextNode = curr->nextNode;
    curr->nextNode = newNode;
    
    
}

//removes the head node from the queue and returns it
qNode pQueue::pop(){
    qNode retNode = *head;
    qNode *temp = head;
    head = head->nextNode;
    free(temp);
    return retNode;
}


