#include "attraction.h"

//constructors 
attraction::attraction () : name(), waitTime(0), paths(), x(0), y(0) {}

attraction::attraction(std::string namein, int waitTimein, std::vector<edge>& pathsin, int x, int y) :
    name(namein), waitTime(waitTimein), paths(pathsin), x(x), y(y) {}

attraction::attraction(std::string namein, int waitTimein, int x, int y) :
    name(namein), waitTime(waitTimein), paths(), x(x), y(y) {}

// get private values
std::string attraction::getname(){
    return name;
}

int attraction::getWaitTime(){
    return waitTime;
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


// operator overload
std::ostream& operator<<(std::ostream& out, const attraction& attr){
    out << attr.name << ", Time at attraction: " << attr.waitTime << " min";
    return out;
}
