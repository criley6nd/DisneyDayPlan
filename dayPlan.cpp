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

    parkGraph park;
    park.addAttr(gate);
    park.addAttr(a);
    park.addAttr(b);
    park.addAttr(c);
    park.addAttr(d);
    park.addAttr(e);
    park.addAttr(f);

    //std::cout << park;
    park.addMustVisit(0);
    park.addMustVisit(5);
    park.addMustVisit(1);
    park.addMustVisit(4);
    park.addMustVisit(3);
    park.addMustVisit(2);
    park.findRoute();
    
    return 0;
}
