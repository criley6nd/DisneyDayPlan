#include "../include/queue.h"
#include <stdlib.h>

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

pQueue::~pQueue(){
    qNode *curr = head;
    while(curr != NULL){
        head = curr->nextNode;
        free(curr);
        curr = head;
    }
}

qNode *pQueue::getHead(){
    return head;
}

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

qNode pQueue::pop(){
    qNode retNode = *head;
    qNode *temp = head;
    head = head->nextNode;
    free(temp);
    return retNode;
}


