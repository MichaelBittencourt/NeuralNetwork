CC = g++
FLAGS = --std=c++11
DEBUG = 0
OPTIMIZE = 3
RM = rm -f
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

.PHONY: debug clean

debug: debug_setup all

debug_setup:
	$(eval OPTIMIZE = 0)
	$(eval DEBUG = 4)
	$(eval DEFINES = $(DEFINES) -DDEBUG)

clean:
	$(RM) $(OBJ) $(BIN)
