#include "parkGraph.h"
#include "queue.h"

parkGraph::parkGraph() : attractions() {}

void parkGraph::readIn(char *fn){
    //reads in a park graph from a given file name
    //file must be written in the following format:
    //name, time, x, y, numedges, edges...

    //creates arrays to receive lines and then to hold split lines
    long unsigned int maxChars = 200;
    char** attractionstr = (char**) malloc(100*sizeof(char*));
    char*** bigarr = (char***) malloc(100 * sizeof(char**));
    for(int i = 0; i < 100; i++){
        bigarr[i] = (char**) malloc(15 * sizeof(char*));
        for(int j = 0; j < 15; j++){
            bigarr[i][j] = (char*) malloc(40 * sizeof(char));
        }
    }
    
    //reads in file by lines
    FILE* afile;
    char *namebuff = (char*)malloc(20*sizeof(char));
    afile = fopen(fn, "r");
    fgets(namebuff, maxChars, afile);
    name = namebuff;
    free(namebuff);
    int count = 0;
    if(afile != NULL){
        while(1){
            if(feof(afile)) break;
            attractionstr[count] = (char*) malloc(maxChars*sizeof(char));
            fgets(attractionstr[count], maxChars, afile);
            char *c = attractionstr[count];
            while(*c != '\n' && *c != '\0'){
                c++;
            }
            *c = '\0';
            count++;
        }
    }

    //splits each line by commas and puts them into bigarr then into an attraction
    //the attraction is then added to the park
    for(int i = 0; i < count; i++){
        split(attractionstr[i], bigarr[i], ',', 15, 40);
        attraction newAttr(bigarr[i][0], atoi(bigarr[i][1]), atoi(bigarr[i][2]) /4, atoi(bigarr[i][3]) / 4);
        addAttr(newAttr);
    }

    //adds edges to the attractions in the park and calulates the distances
    for(int i = 0; i < count; i++){
        std::vector<edge> bigEdges; 
        for(int j = 1; j <= atoi(bigarr[i][4]); j++){
            edge temp(i,atoi(bigarr[i][4 + j]));
            temp.setWeight(findDist(attractions[i], attractions[atoi(bigarr[i][4 + j])]));
            bigEdges.push_back(temp);
        }
        attractions[i].paths = bigEdges;
    }


    //frees memory
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 15; j++){
            free(bigarr[i][j]);
        }
        free(bigarr[i]);
    }    
    free(bigarr);

    for(int i = 0; i < count; ++i){
        free(attractionstr[i]);
    }
    free(attractionstr);
}

std::string parkGraph::getName(){
    return name;
}

int split(char* buf, char** splits, char delim, int max, int len){
    //splits a char* into a char** by a given delimeter
    char* r = buf;
    char* dubbuff = (char*)malloc(len * sizeof(char));
    int elements = 0;
    int buffspot = 0;
    while(*r != '\0' && elements <= max){
        if(*r != delim){
            dubbuff[buffspot] = *r;
            r++;
            buffspot++;
        }
        else{
            r++;
            dubbuff[buffspot] = '\0';
            memcpy(splits[elements], dubbuff, len * sizeof(char));
            
            buffspot = 0;
            elements++;
        }
    }
    free(dubbuff);

    return elements;
}

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
    //call from main
    float time = 0;
    sortVisitOrder();
    std::cout << attractions[0] << std::endl;
    for(std::vector<int>::iterator it = mustVisit.begin(); it != mustVisit.end() - 1; it++){
        time = findpath(*it,*(it + 1), time);
    }
    
}

float parkGraph::findpath(int start, int end, float startTime){
    edge curr;

    //parents stores the parent values of each node when traversing
    int parents[attractions.size()];
    //weights stores the shortest possible time to get to each node
    float weights[attractions.size()];
    //times stores the time the user will visit each attraction
    float times[attractions.size()];
    //default all weights to a very large number
    for(int i = 0; i < attractions.size(); i++){
        weights[i] = (float)100000;
    }

    //begin traversal by inserting the starting node
    parents[start] = -1;
    weights[start] = 0;
    times[start] = startTime;
    pQueue pq;
    std::vector<edge> paths;
    paths = attractions[start].getEdges();
        if(paths.size() != 0){
            for(auto & path : paths){
                pq.insert(path, pathWeight(path, end));        
            }
        }

    
    //while there are still elements in the priorety queue
    //will check to see if the new path is better than the previous best path
    //if it is it will replace the old path and add the new edges to the queue
    while(pq.getHead() != NULL){
        curr = pq.pop().getPath();
        
        if(pathWeight(curr, end) + weights[curr.getCurrAttr()] < weights[curr.getNextAttr()]){
            weights[curr.getNextAttr()] = pathWeight(curr,end) + weights[curr.getCurrAttr()];
            times[curr.getNextAttr()] = pathTime(curr) + times[curr.getCurrAttr()];
            parents[curr.getNextAttr()] = curr.getCurrAttr();
            paths = attractions[curr.getNextAttr()].getEdges();

            if(paths.size() != 0){
                for(auto & path : paths){
                    pq.insert(path, pathWeight(path, end));    
                }
            }
        }
        
    }

    //creates a stack to print out the rides by walking back through
    //the parents until it hits -1, then using the stack, it will print them
    //in the order that they are visited
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
        float waitTime = times[printStack.back()] - attractions[printStack.back()].getWaitTime();
        if((int)waitTime % 60 >= 10){
            std::cout << (((int)waitTime) / 60) << ":" << (((int)waitTime) % 60) << " " << attractions[printStack.back()] << std::endl;
        }
        else{
            std::cout << (((int)waitTime) / 60) << ":0" << (((int)waitTime) % 60) << " " << attractions[printStack.back()] << std::endl;
        }
        printStack.pop_back();
    }
    return times[end];

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

float parkGraph::pathTime(edge path){
    return path.getWeight() + attractions[path.getNextAttr()].getWaitTime();
}


//finds the euclidian distance between two nodes on the graph
double findDist(attraction a, attraction b){
    int dx = a.getx() - b.getx();
    int dy = a.gety() - b.gety();
    return sqrt(dx * dx + dy * dy);
}

