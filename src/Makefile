HEADER=/usr/local/include
STD_LIB=-stdlib=libstdc++

SRC_S=A_Set.cpp AbstractSet.cpp BDD_Builder.cpp BDD_Node.cpp B_Polyhedron.cpp CCI.cpp Drifter.cpp MaximumMap.cpp Problem.cpp T_Polyhedron.cpp Transformer.cpp Utilities.cpp

all 	:$(SRC_S)
	g++ -g -c $(SRC_S) -I$(HEADER) $(STD_LIB) 
clean:
	rm -rf *.o

