#include <iostream>

#include "parkGraph.h"

int main(){

    attraction a("space mountain", 5, 5);
    attraction b("peter pan", 60, 5);
    std::cout << a << std::endl;

    parkGraph park;
    park.addAttr(a);
    park.addAttr(b);
    std::cout << park;
    
    return 0;
}
