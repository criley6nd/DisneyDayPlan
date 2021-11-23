#include <iostream>
#include <vector>
#include <string>
#include "attraction.h"

class parkGraph{
    private:
        std::vector<attraction> attractions;
    public:
        parkGraph();
        int addAttr(attraction a);
        void findRoute();
        friend std::ostream& operator<<(std::ostream& out, const parkGraph& park);
        
};