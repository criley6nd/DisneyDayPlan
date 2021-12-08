#ifndef EDGE_H
#define EDGE_H

class edge{
    private:
        int nextAttr;
        int currAttr;
        float weight;
    public:
        edge();
        edge(int currAttr, int nextAttr);
        void setWeight(float newWeight);
        int getNextAttr();
        float getWeight();
        int getCurrAttr();
    
};

#endif