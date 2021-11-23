#include "parkGraph.h"

parkGraph::parkGraph() : attractions() {}

//adds attraction to parkGraph and returns index
int parkGraph::addAttr(attraction a){
    attractions.push_back(a);
    return attractions.size();
}

std::ostream& operator<<(std::ostream& out, const parkGraph& park){
    for(int i = 0; i < park.attractions.size(); i++){
        out << i << ": " << park.attractions[i] << "\n";
    }
    return out;
}


void parkGraph::findRoute(){

    //search algorithm goes here
}