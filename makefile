dayPlan : dayPlan.c parkGraph.o
	g++ -o dayPlan dayPlan.c parkGraph.o

parkGraph.o : parkGraph.c attraction.o
	g++ -o parkGraph.o parkGraph.c attraction.o

attraction.o : attraction.c edge.o
	g++ -o attraction.o attraction.c edge.o

edge.o : edge.c
	g++ -o edge.o edge.c
