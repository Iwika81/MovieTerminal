# Default target
all: MovieTerminal

MovieTerminal: MovieTerminal.cpp cartelera.cpp
    g++ -o MovieTerminal cartelera.cpp MovieTerminal.cpp -I
cartelera: cartelera.hpp
    g++ -o cartelera cartelera.cpp
clean:
    rm -f main.o
