g++ -c edge.cpp
g++ -c .\attraction.cpp
g++ -c .\parkGraph.cpp -lm
g++ .\dayPlan.cpp .\parkGraph.o .\attraction.o .\edge.o