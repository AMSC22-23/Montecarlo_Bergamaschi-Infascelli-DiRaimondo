#include <iostream>
#include <fstream>
#include "HyperRectangle.cpp"
#include "HyperSphere.cpp"

using namespace std;

int main(int argc, char** argv){
    int type_domain = 0;

    if(argc < 0){
        return -1;
    }
    //take the type of domain
    type_domain = atoi(argv[1]);

    if(type_domain == 0){
        //hyperSphere
        HyperSphere* hs = new HyperSphere();
    }
    else{       //
        //hyperRectangle
        HyperRectangle* hr = new HyperRectangle();
    }
    ifstream input("input.txt");
    return 0;
} 
