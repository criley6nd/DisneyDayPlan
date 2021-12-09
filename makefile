# Author: Connor Riley
# E-mail: criley6@nd.edu
#
# This is the Makefile for PC07


PP := g++


FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe
FUNC1 := parkGraph
FUNC2 := attraction
FUNC3 := queue
FUNC4 := edge
EX := dayPlan

# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)


$(OBJ)/$(FUNC1).o: $(SRC)/$(FUNC1).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(FUNC1).cpp -o $@

$(OBJ)/$(FUNC2).o: $(SRC)/$(FUNC2).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(FUNC2).cpp -o $@

$(OBJ)/$(FUNC3).o: $(SRC)/$(FUNC3).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(FUNC3).cpp -o $@

$(OBJ)/$(FUNC4).o: $(SRC)/$(FUNC4).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(FUNC4).cpp -o $@

$(OBJ)/$(EX).o: $(SRC)/$(EX).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(EX).cpp -o $@


objs := $(OBJ)/$(FUNC1).o $(OBJ)/$(FUNC2).o $(OBJ)/$(FUNC3).o $(OBJ)/$(FUNC4).o $(OBJ)/$(EX).o


$(EX): $(objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/$(EX) $(objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*