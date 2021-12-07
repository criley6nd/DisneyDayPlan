#include "queue.h"
#include <iostream>

int main(){

    pQueue q;
    edge e1(1);

    
    q.insert(e1, 4);
    //std::cout << "hi" << std::endl;
    q.insert(e1, 1);
    q.insert(e1, 5);
    q.insert(e1, 3);
    q.insert(e1, 0);
    

    qNode prin = q.pop();
    std::cout << prin.getWeight() << std::endl;

    
    prin = q.pop();
    std::cout << prin.getWeight() << std::endl;

    prin = q.pop();
    std::cout << prin.getWeight() << std::endl;

    prin = q.pop();
    std::cout << prin.getWeight() << std::endl;
    prin = q.pop();
    std::cout << prin.getWeight() << std::endl;


    return 0;
}