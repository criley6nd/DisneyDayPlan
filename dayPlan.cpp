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
    
    std::vector<edge> tempPaths;
    tempPaths.push_back(edge(1));
    tempPaths[0].setWeight(findDist(gate, a));
    gate.paths = tempPaths;

    tempPaths.clear();
    tempPaths.push_back(edge(2));
    tempPaths.push_back(edge(4));
    tempPaths[0].setWeight(findDist(a, b));
    tempPaths[1].setWeight(findDist(a, d));
    a.paths = tempPaths;

    tempPaths.clear();
    tempPaths.push_back(edge(5));
    //tempPaths.push_back(edge(0));
    tempPaths[0].setWeight(findDist(d, e));
    //tempPaths[1].setWeight(findDist(d, gate));
    d.paths = tempPaths;

    parkGraph park;
    park.addAttr(gate);
    park.addAttr(a);
    park.addAttr(b);
    park.addAttr(c);
    park.addAttr(d);
    park.addAttr(e);
    park.addAttr(f);


    //std::cout << park;
    int len = 3;
    int rides[] = {0,5,2};
    park.addMustVisit(rides, len);
    park.planDay();
    
    return 0;
}
