OBJS = fileManager.o solver.o solverManager.o main.o cthreadpool.o
CPP = g++
FLAGES = -std=c++11 -O2 

sudoku_solve: $(OBJS)
	$(CPP) -o $@ $(OBJS) -lpthread

main.o: main.cpp 
	$(CPP) $(FLAGES) -c $^ -lpthread

fileManager.o: fileManager.cpp fileManager.hpp
	$(CPP) $(FLAGES) -c $^ -lpthread

solver.o: solver.cpp solver.hpp
	$(CPP) $(FLAGES) -c $^ -lpthread

solverManager.o: solverManager.cpp solverManager.hpp
	$(CPP) $(FLAGES) -c $^ -lpthread

cthreadpool.o: cthreadpool.h cthreadpool.cpp
	$(CPP) $(FLAGES) -c $^ -lpthread

PHONY: clean

clean:
	rm *.o *.hpp.gch sudoku_solve