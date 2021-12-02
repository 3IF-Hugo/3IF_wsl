CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=sejours

all: $(EXEC)

sejours : Interface.o TrajetCompose.o TrajetSimple.o Trajet.o Element.o LinkedList.o Catalogue.o
	$(CXX) -o $@ $^
	
Trajet.o : Trajet.cpp
	$(CXX) -c -g $< $(CFLAGS)
	
TrajetSimple.o : TrajetSimple.cpp
	$(CXX) -c -g $< $(CFLAGS)
	
TrajetCompose.o : TrajetCompose.cpp
	$(CXX) -c -g $< $(CFLAGS)
	
Interface.o : Interface.cpp
	$(CXX) -c -g $< $(CFLAGS)

Element.o : Element.cpp
	$(CXX) -c -g $< $(CFLAGS)

LinkedList.o : LinkedList.cpp
	$(CXX) -c -g $< $(CFLAGS)

Catalogue.o : Catalogue.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)