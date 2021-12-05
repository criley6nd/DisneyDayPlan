#include <iostream>
#include <vector>
#include <string>
#include "edge.h"


//class for an attraction to be a node on the graph
//includes name of attraction, wait time, and time spent at the attraction
//also includes coordinates to be used in the search algorithm
class attraction{
    private:
        std::string name;
        std::vector<edge> paths;
        int waitTime;
        int rideTime;
        int x;
        int y;
    public:
        attraction();
        attraction(std::string namein, int waitTimein, int rideTimein, std::vector<edge>& pathsin, int x, int y);
        attraction(std::string namein, int waitTimein, int rideTimein, int x, int y);
        std::string getname();
        int getWaitTime();
        int getRideTime();
        int getx();
        int gety();
        std::vector<edge> getEdges();
        void addPaths(edge newPaths[], int len);
        friend std::ostream& operator<<(std::ostream& out, const attraction& attr);

};