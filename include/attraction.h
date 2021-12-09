#include <iostream>
#include <vector>
#include <string>
#include "edge.h"
#ifndef ATTRACTION_H
#define ATTRACTION_H

//class for an attraction to be a node on the graph
//includes name of attraction, and time spent at the attraction
//also includes coordinates to be used in the search algorithm
class attraction{
    private:
        std::string name;
        int waitTime;
        int x;
        int y;
    public:
        attraction();
        attraction(std::string namein, int waitTimein, std::vector<edge>& pathsin, int xin, int yin);
        attraction(std::string namein, int waitTimein, int xin, int yin);
        std::string getname();
        int getWaitTime();
        int getx();
        int gety();

        std::vector<edge> paths;

        std::vector<edge> getEdges();
        void addPaths(std::vector<edge> newEdges);
        friend std::ostream& operator<<(std::ostream& out, const attraction& attr);

};

#endif