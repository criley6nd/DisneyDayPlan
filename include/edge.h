#ifndef EDGE_H
#define EDGE_H

//class to store an edge on the park graph 
//contains currAttr to represent attraction it is leaving
//nextAttr represents where it is going and weight is the 
//path weight
class edge{
    private:
        int nextAttr;
        int currAttr;
        float weight;
    public:
        edge();
        edge(int currAttrin, int nextAttrin);
        void setWeight(float newWeight);
        int getNextAttr();
        float getWeight();
        int getCurrAttr();
    
};

#endif