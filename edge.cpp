#include "edge.h"

edge::edge() : nextAttr(0), weight(0) {}

int edge::getNextAttr(){
    return nextAttr;
}
int edge::getWeight(){
    return weight;
}