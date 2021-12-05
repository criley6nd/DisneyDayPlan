#include "edge.h"

edge::edge() : nextAttr(0), weight(0) {}

edge::edge(int nextAttr) : nextAttr(nextAttr), weight(0) {}

void edge::setWeight(float newWeight){
    weight = newWeight;
}

int edge::getNextAttr(){
    return nextAttr;
}
float edge::getWeight(){
    return weight;
}