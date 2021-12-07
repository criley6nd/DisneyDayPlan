g++ -c edge.cpp
g++ -c .\attraction.cpp
g++ -c .\parkGraph.cpp -lm
g++ -c .\queue.cpp
g++ -Wall .\dayPlan.cpp .\parkGraph.o .\attraction.o .\edge.o .\queue.o