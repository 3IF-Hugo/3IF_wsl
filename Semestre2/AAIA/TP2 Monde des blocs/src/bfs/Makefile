CC=g++
CFLAGS=-I. -std=c++11
DEPS=
OBJ=bfs.o
TARGET=bfs
MAKEFILE=Makefile

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ): $(MAKEFILE)

$(TARGET): $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

clean:
	rm $(OBJ) $(TARGET)
