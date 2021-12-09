#include <iostream>

#include "parkGraph.h"

int main(int argc, char *argv[]){

    parkGraph park;
    /*
    // initialize attractions for test
    attraction gate("Main gate", 0, 0, 0);
    attraction a("space mountain", 5, 1, 1); 
    attraction b("peter pan", 60, 2, 2);
    attraction c("peter", 6,2, 3);
    attraction d("pan", 600, 3, 3);
    attraction e("wendy", 60, 10, 10);
    attraction f("john", 60, 2, 1);
    
    std::vector<edge> tempPaths;
    tempPaths.push_back(edge(0,1));
    tempPaths.push_back(edge(0,3));
    tempPaths[0].setWeight(findDist(gate, c));
    tempPaths[0].setWeight(findDist(gate, a));
    gate.paths = tempPaths;

    tempPaths.clear();
    tempPaths.push_back(edge(2,3));
    //tempPaths.push_back(edge(2,5));
    tempPaths[0].setWeight(findDist(b, c));
    //tempPaths[1].setWeight(findDist(b, e));
    b.paths = tempPaths;

    tempPaths.push_back(edge(3,1));
    tempPaths.push_back(edge(3,4));
    tempPaths[0].setWeight(findDist(c, a));
    tempPaths[0].setWeight(findDist(c, d));
    c.paths = tempPaths;

    tempPaths.clear();
    tempPaths.push_back(edge(1,2));
    tempPaths.push_back(edge(1,4));
    tempPaths[0].setWeight(findDist(a, b));
    tempPaths[1].setWeight(findDist(a, d));
    a.paths = tempPaths;

    tempPaths.clear();
    tempPaths.push_back(edge(4,5));
    tempPaths.push_back(edge(4, 0));
    tempPaths[0].setWeight(findDist(d, e));
    tempPaths[1].setWeight(findDist(d, gate));
    d.paths = tempPaths;

    parkGraph park;
    park.addAttr(gate);
    park.addAttr(a);
    park.addAttr(b);
    park.addAttr(c);
    park.addAttr(d);
    park.addAttr(e);
    park.addAttr(f);
    */

    //char *fn = "attractions.txt";
    park.readIn(argv[1]);
    std::cout << "\n" << park.getName() << std::endl;

    std::cout << park;
    std::cout << "What attractions are your must visits? (enter a 0 when done or a max of 25)" << std::endl;
    int inp, len = 1, rides[25];
    std::cin >> inp;
    rides[0] = 0;
    while(inp != -1 && len < 25){
        rides[len] = inp;
        len++;
        std::cin >> inp;
        
    }
   
    park.addMustVisit(rides, len);
    park.planDay();
    

    return 0;
}
