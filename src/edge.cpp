#include "../include/edge.h"

//constructors
edge::edge() : nextAttr(0), currAttr(0), weight(0) {}

edge::edge(int currAttrin, int nextAttrin) : nextAttr(nextAttrin), currAttr(currAttrin), weight(0) {}

//get and set functions
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