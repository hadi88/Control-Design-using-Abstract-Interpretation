HEADER=/usr/local/include
STD_LIB=-stdlib=libstdc++

SRC_F= Input.cpp Mode.cpp PartitioningMethod.cpp I_Polyhedron.cpp

all 	:$(SRC_F)
	bison -b Grammar -d Grammar.ypp
	flex -o Tokens.cpp Tokens.lpp
	g++ -g -c $(SRC_F) Tokens.cpp Grammar.tab.cpp -I$(HEADER) $(STD_LIB) 
clean:
	rm -rf Grammar.tab.*
	rm -rf Tokens.cpp
	rm -rf *.o
