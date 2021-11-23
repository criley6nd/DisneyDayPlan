#include "attraction.h"

attraction::attraction () : name(), waitTime(0), rideTime(0), paths() {}

attraction::attraction(std::string namein, int waitTimein, int rideTimein, std::vector<edge>& pathsin) :
    name(namein), waitTime(waitTimein), rideTime(rideTimein), paths(pathsin){}

attraction::attraction(std::string namein, int waitTimein, int rideTimein) :
    name(namein), waitTime(waitTimein), rideTime(rideTimein), paths(){}



std::string attraction::getname(){
    return name;
}

int attraction::getWaitTime(){
    return waitTime;
}

int attraction::getRideTime(){
    return rideTime;
}

std::ostream& operator<<(std::ostream& out, const attraction& attr){
    out << attr.name << ", wait time: " << attr.waitTime << ", ride time: " << attr.rideTime;
    return out;
}
