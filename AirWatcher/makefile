CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=airWatcher

all: $(EXEC)

airWatcher : User.o PrivateUser.o Provider.o Cleaner.o Attribute.o Sensor.o Measurement.o Service.o Interface.o
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)