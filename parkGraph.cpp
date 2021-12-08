#include "parkGraph.h"
#include "queue.h"

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

void parkGraph::addMustVisit(int attr[], int len){
    for(int i = 0; i < len; i++){
        addMustVisit(attr[i]);
    }
}

void parkGraph::planDay(){
    sortVisitOrder();
    std::cout << attractions[0] << std::endl;
    for(std::vector<int>::iterator it = mustVisit.begin(); it != mustVisit.end() - 1; it++){
        findpath(*it,*(it + 1));
    }
    
}

void parkGraph::findpath(int start, int end){
    edge curr;
    float time = 0;
    int parents[attractions.size()];
    float weights[attractions.size()];
    float times[attractions.size()];
    for(int i = 0; i < attractions.size(); i++){
        weights[i] = (float)100000;
    }
    parents[start] = -1;
    weights[start] = 0;
    pQueue pq;


    std::vector<edge> paths;
    paths = attractions[start].getEdges();
        if(paths.size() != 0){
            for(auto & path : paths){
                pq.insert(path, pathWeight(path, end));        
            }
        }

    

    while(pq.getHead() != NULL){
        curr = pq.pop().getPath();
        
        if(pathWeight(curr, end) + weights[curr.getCurrAttr()] < weights[curr.getNextAttr()]){
            weights[curr.getNextAttr()] = pathWeight(curr,end) + weights[curr.getCurrAttr()];
            parents[curr.getNextAttr()] = curr.getCurrAttr();
            paths = attractions[curr.getNextAttr()].getEdges();

            if(paths.size() != 0){
                for(auto & path : paths){
                    pq.insert(path, pathWeight(path, end));    
                
                }
            }
        }
        
        
        
        
    }

    std::vector<int> printStack;
    int i = end;
    printStack.push_back(i);
    i = parents[i];
    while(i != -1){
        if(printStack.back() != i){
            printStack.push_back(i);
        }
        i = parents[i];
    }

    printStack.pop_back();
    while(printStack.size() > 0){
        std::cout << printStack.back() << ": " << attractions[printStack.back()] << std::endl;
        printStack.pop_back();
    }


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
}

float parkGraph::pathWeight(edge path, int dest){
    return path.getWeight() + attractions[path.getNextAttr()].getWaitTime() + findDist(attractions[path.getNextAttr()], attractions[dest]);
}


//finds the euclidian distance between two nodes on the graph
double findDist(attraction a, attraction b){
    int dx = a.getx() - b.getx();
    int dy = a.gety() - b.gety();
    return sqrt(dx * dx + dy * dy);
}

