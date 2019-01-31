EXEC=main
CFLAGS=-std=c++11
LDFLAGS=
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cpp)
HED= Personnage.h
OBJ= $(SRC:.cpp=.o)
CC=g++ -std=c++11 -g

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

%.o: %.cpp
	$(CC) -Wall  -c $< -o $@

.PHONY: all clean mrproper

clean:
		rm -rf *.o

mrproper : clean
		rm -f $(OBJECTS) $(EXEC) 
