#include <iostream>
#include <vector>
#include <string>
#include "edge.h"


//class for an attraction to be a node on the graph
//includes name of attraction, wait time, and time spent at the attraction
class attraction{
    private:
        std::string name;
        int waitTime;
        int rideTime;
        int x;
        int y;
    public:
        std::vector<edge> paths;
        attraction();
        attraction(std::string namein, int waitTimein, int rideTimein, std::vector<edge>& pathsin);
        attraction(std::string namein, int waitTimein, int rideTimein);
        std::string getname();
        int getWaitTime();
        int getRideTime();
        int getx();
        int gety();
        friend std::ostream& operator<<(std::ostream& out, const attraction& attr);

};