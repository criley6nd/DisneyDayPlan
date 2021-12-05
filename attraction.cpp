#include "attraction.h"

//constructors 
attraction::attraction () : name(), waitTime(0), rideTime(0), paths(), x(0), y(0) {}

attraction::attraction(std::string namein, int waitTimein, int rideTimein, std::vector<edge>& pathsin, int x, int y) :
    name(namein), waitTime(waitTimein), rideTime(rideTimein), paths(pathsin), x(x), y(y) {}

attraction::attraction(std::string namein, int waitTimein, int rideTimein, int x, int y) :
    name(namein), waitTime(waitTimein), rideTime(rideTimein), paths(), x(x), y(y) {}

// get private values
std::string attraction::getname(){
    return name;
}

int attraction::getWaitTime(){
    return waitTime;
}

int attraction::getRideTime(){
    return rideTime;
}

int attraction::getx(){
    return x;
}

int attraction::gety(){
    return y;
}

std::vector<edge> attraction::getEdges(){
    return paths;
}

void attraction::addPaths(edge newPaths[], int len){
    for(int i = 0; i < len; i++){
        paths.push_back(newPaths[i]);
    }
}

// operator overload
std::ostream& operator<<(std::ostream& out, const attraction& attr){
    out << attr.name << ", wait time: " << attr.waitTime << ", ride time: " << attr.rideTime;
    return out;
}
