#include <iostream>

#include "parkGraph.h"

int main(){

    // initialize attractions for test
    attraction gate("Main gate", 0, 0, 0, 0);
    attraction a("space mountain", 5, 5, 1, 1); 
    attraction b("peter pan", 60, 5, 2, 2);
    attraction c("peter", 60, 5, 2, 3);
    attraction d("pan", 60, 5, 3, 3);
    attraction e("wendy", 60, 5, 10, 10);
    attraction f("john", 60, 5, 2, 1);
    //std::cout << a << std::endl;
    edge paths[2];
    paths[0] = edge(1);
    paths[1] = edge(2);
    paths[0].setWeight(findDist(gate,a));
    paths[1].setWeight(findDist(gate,d));
    gate.addPaths(paths, 2);

    parkGraph park;
    park.addAttr(gate);
    park.addAttr(a);
    park.addAttr(b);
    park.addAttr(c);
    park.addAttr(d);
    park.addAttr(e);
    park.addAttr(f);


    //std::cout << park;
    int len = 6;
    int rides[] = {0,5,1,4,3,2};
    park.addMustVisit(rides, len);
    park.findRoute();
    
    return 0;
}
