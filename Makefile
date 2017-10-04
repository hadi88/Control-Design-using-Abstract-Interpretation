HEADER=/usr/local/include
LIBRARY=/usr/local/lib
GMP_LIB=-lgmp -lgmpxx
PPL_LIB=-lppl
STD_LIB=-stdlib=libstdc++

OBJ_S=src/Utilities.o
OBJ_F=frontend/Tokens.o
EXE=Synthesizer

all:	$(OBJ_F) $(OBJ_S)
	g++ -g -o $(EXE) frontend/*.o src/*.o -I$(HEADER) -L$(LIBRARY) $(STD_LIB) $(GMP_LIB) $(PPL_LIB)

$(OBJ_F):
	cd frontend; make 

$(OBJ_S):
	cd src; make

clean-f:
	cd frontend; make clean
clean-s:
	cd src; make clean
clean:	
	cd frontend; make clean
	cd src; make clean
	rm -rf $(EXE)


