.PHONY: all
all: main

main: Domain.hpp HyperRectangle.cpp HyperSphere.cpp MontecarloIntegration.cpp main.cpp
	g++ -std=c++20 -I../muparser-2.3.4/include main.cpp HyperRectangle.cpp HyperSphere.cpp MontecarloIntegration.cpp -o main -L../muparser-2.3.4 -lmuparser -lstdc++ -lm -fopenmp -O3

.PHONY: clear
clear:
	rm -f main