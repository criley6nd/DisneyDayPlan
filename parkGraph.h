#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "attraction.h"


//class to be used to store the park map and find the route for the day
class parkGraph{
    private:
    // vector to store the different attractions
        std::vector<attraction> attractions;
        std::vector<int>mustVisit;
        void sortVisitOrder();
    public:
        parkGraph();
        int addAttr(attraction a);
        void planDay();
        void findRoute(int start, int end);
        void addMustVisit(int attr);
        void addMustVisit(int attr[], int len);
        float pathWeight(edge path, int dest);
        float findpath(int start, int end, float startTime);
        float pathTime(edge path);
        friend std::ostream& operator<<(std::ostream& out, const parkGraph& park);
        
};

double findDist(attraction a, attraction b);