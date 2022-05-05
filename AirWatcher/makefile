CXX=g++
CFLAGS=-Wall -ansi -pedantic -std=c++11
EXEC=airWatcher

all: $(EXEC)

airWatcher : User.o PrivateUser.o Provider.o Cleaner.o Sensor.o Attribute.o Measurement.o Lecture.o Service.o Interface.o 
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -g $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)