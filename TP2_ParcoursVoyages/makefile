CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=sejours

all: $(EXEC)

sejours : Interface.o TrajetCompose.o TrajetSimple.o Trajet.o Element.o LinkedList.o Catalogue.o
	$(CXX) -o $@ $^
	
%.o : %.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)