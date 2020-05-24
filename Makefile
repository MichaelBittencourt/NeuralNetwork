CC = g++
FLAGS = --std=c++11
INCLUDES :=
DEFINES :=

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = prog

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(INCLUDES) $(DEFINES) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(INCLUDES) $(DEFINES) $(FLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(BIN)
