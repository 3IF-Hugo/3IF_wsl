CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=analog

all: $(EXEC)

analog : LectureLog.o Application.o Interface.o
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf *.dot
	rm -rf *.png