CC=g++
CFLAGS=-I. -std=c++11
DEPS=
OBJ=astar.o
TARGET=astar
MAKEFILE=Makefile

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ): $(MAKEFILE)

$(TARGET): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

optim: CFLAGS += -O3
optim: $(TARGET)

clean:
	rm $(OBJ) $(TARGET)
