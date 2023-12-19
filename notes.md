# General notes
- You should not upload the compiled executable or build files
- Nice readme, I have added some suggestions to CMake and build instructions. Would be nice to have explicit command to change number of threads

## Minor
- It would be better is muparser was included as a submodule

# Code
## Major
- it is not a good practice to use `using namespace std;`, in particular for not limited scopes
- some methods should be `const`
- the function to integrate and the domain are two separate entities, it would make more sense to treat them in two different data structures

## Minor
- parameter files shuould be in a different directory