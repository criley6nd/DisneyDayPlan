#include <iostream>
#include <vector>
#include <string>
#include "attraction.h"


//class to be used to store the park map and find the route for the day
class parkGraph{
    private:
    // vector to store the different attractions
        std::vector<attraction> attractions;
    public:
        parkGraph();
        int addAttr(attraction a);
        void findRoute();
        friend std::ostream& operator<<(std::ostream& out, const parkGraph& park);
        
};