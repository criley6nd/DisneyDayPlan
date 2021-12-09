#include "../include/edge.h"

edge::edge() : nextAttr(0), weight(0) {}

edge::edge(int currAttr, int nextAttr) : nextAttr(nextAttr), weight(0), currAttr(currAttr) {}

void edge::setWeight(float newWeight){
    weight = newWeight;
}

int edge::getNextAttr(){
    return nextAttr;
}
float edge::getWeight(){
    return weight;
}

int edge::getCurrAttr(){
    return currAttr;
}