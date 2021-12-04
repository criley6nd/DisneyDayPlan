#include "parkGraph.h"

parkGraph::parkGraph() : attractions() {}

//adds attraction to parkGraph and returns index
int parkGraph::addAttr(attraction a){
    attractions.push_back(a);
    return attractions.size();
}

std::ostream& operator<<(std::ostream& out, const parkGraph& park){
    for(int i = 0; i < park.attractions.size(); i++){
        out << i << ": " << park.attractions[i] << "\n";
    }
    return out;
}

void parkGraph::addMustVisit(int attr){
    mustVisit.push_back(attr);
}

void parkGraph::findRoute(){
    (*this).sortVisitOrder();
    
}

void parkGraph::sortVisitOrder(){
    // finds closest attraction to the gate to start with
    //gate uses default constructor for coordinates (0,0)
    
    double minDist = 1000;
    double dist;
    int closest, temp;
    for(int i = 0; i < mustVisit.size() - 1; i++){
        for(int j = i + 1; j < mustVisit.size(); j++){
            dist = findDist(attractions[mustVisit[i]], attractions[mustVisit[j]]);
            if(dist < minDist){
                minDist = dist;
                closest = j;
            }
        }

        temp = mustVisit[i + 1];
        mustVisit[i+1] = mustVisit[closest];
        mustVisit[closest] = temp;
        minDist = 1000;
        
    }


    for(auto & node : mustVisit){
        std::cout << node << std::endl;
    }


    

}


//finds the euclidian distance between two nodes on the graph
double findDist(attraction a, attraction b){
    int dx = a.getx() - b.getx();
    int dy = a.gety() - b.gety();
    return sqrt(dx * dx + dy * dy);
}
