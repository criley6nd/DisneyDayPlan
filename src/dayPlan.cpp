#include <iostream>

#include "../include/parkGraph.h"

int main(int argc, char *argv[]){

    // checks for correct number of arguments
    if(argc != 2){
        std::cout << "Enter a file name" << std:: endl;
        return 1;
    }

    //reads in park from file
    parkGraph park;
    park.readIn(argv[1]);
    
    //prints out park as list of attractions with the name at the top
    std::cout << "\n" << park.getName() << std::endl;
    std::cout << park;
    std::cout << "What attractions are your must visits? (enter a -1 when done or a max of 25)" << std::endl;

    //takes in user input for attractions to visit until user enters -1
    int inp, len = 1, rides[25];
    std::cin >> inp;
    rides[0] = 0;
    while(inp != -1 && len < 25){
        rides[len] = inp;
        len++;
        std::cin >> inp;
        
    }
   
    //adds the user inputted list to the park and plans the day
    park.addMustVisit(rides, len);
    park.planDay();
    

    return 0;
}
