#include "../include/attraction.h"

//constructors 
attraction::attraction () : name(), waitTime(0), x(0), y(0), paths() {}

attraction::attraction(std::string namein, int waitTimein, int xin, int yin) :
    name(namein), waitTime(waitTimein),  x(xin), y(yin), paths()  {}

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
