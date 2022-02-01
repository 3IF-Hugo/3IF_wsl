CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=analog

all: $(EXEC)

analog : InfoLog.o LectureLog.o Graphe.o Interface.o
	$(CXX) -o $@ $^
	
%.o : %.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf *.dot
	rm -rf *.png