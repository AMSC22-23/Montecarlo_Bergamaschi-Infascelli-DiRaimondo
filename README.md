# Montecarlo_Bergamaschi-Infascelli-DiRaimondo

## Compiling process
In order to compile the program, follow these simple steps:
1. Download the git repository and type cd Montecarlo
2. type cd Montecarlo_Bergamaschi-Infascelli-DiRaimondo/
3. type cd cd muparser-2.3.4/ and use the following commands:
    cmake . -DENABLE_SAMPLES=OFF -DENABLE_OPENMP=ON -DENABLE_WIDE_CHAR=OFF -DBUILD_SHARED_LIBS=ON
    make
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/jellyfish/shared-folder/Montecarlo_Bergamaschi-Infascelli-DiRaimondo/muparser-2.3.4

## MuParser library
The MuParser library is a math library used to do the parsing of mathematical expressions and it is written in C++. It works by transforming a mathematical expression into bytecode and precalculating constant parts of the expression. 
For more information:
    https://beltoforion.de/en/muparser/

## Input argument
./main nomeFile.txt x y

nomeFile.txt is the name of the file that contains the input;
x indicates the type of the domain:
    0 = hyperSphere domain
    1 = hyperRectangle domain
y indicates the number of samples to be generated.

## Description of the input file
### Case 0 (HyperSphere):
    The first row contains two numbers, respectively the dimension and the radius;
    The second row contains the coordinates of the center;
    The last row contains the function.

### Case 1 (HyperRectangle):
    The first row contains the dimension;
    The second row contains the coordinates of two opposite vertices:
        for example, if the two points are (x1,y1) and (x2,y2), the coordinates will be written as follows: x1 x2 y1 y2.
    The last row contains the function.

## How to run the program
Type the following commands:
1. cd src
2. make
3. ./main nomeFile.txt x y