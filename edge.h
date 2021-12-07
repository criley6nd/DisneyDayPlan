#ifndef EDGE_H
#define EDGE_H

class edge{
    private:
        int nextAttr;
        float weight;
    public:
        edge();
        edge(int nextAttr);
        void setWeight(float newWeight);
        int getNextAttr();
        float getWeight();
    
};

#endif