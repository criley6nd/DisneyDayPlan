#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "attraction.h"
#ifndef PARKGRAPH_H
#define PARKGRAPH_H


//class to be used to store the park map and find the route for the day
class parkGraph{
    private:
    // vector to store the different attractions
        std::vector<attraction> attractions;
        std::vector<int>mustVisit;
        std::string name;
        void sortVisitOrder();
    public:
        parkGraph();
        int addAttr(attraction a);
        std::string getName();
        void planDay();
        void findRoute(int start, int end);
        void addMustVisit(int attr);
        void addMustVisit(int attr[], int len);
        float pathWeight(edge path, int dest);
        float findpath(int start, int end, float startTime);
        float pathTime(edge path);
        void readIn(char *fn);
        friend std::ostream& operator<<(std::ostream& out, const parkGraph& park);
        
};

double findDist(attraction a, attraction b);
int split(char* buf, char** splits, char delim, int max, int len);

#endif