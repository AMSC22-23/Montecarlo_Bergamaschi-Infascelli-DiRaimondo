# General notes
- `Makefile` must have the correct capitalization in Linux
- `.vscode` and `.idea` folders should be in the gitignore
- You should not upload the compiled executable or build files
- Nice readme

## Minor
- It would be better is muparser was included as a submodule

# Code
## Major
- it is not a good practice to use `using namespace std;`, in particular for not limited scopes
- do not understand why sometimes you use `Coordinates` and sometimes `std::vector` for coordinates
- some methods should be `const`
- the function to integrate and the domain are two separate entities, it would make more sense to treat them in two different data structures

## Minor
- could use `std::vector` or `std::array` to work in N-dimesions and not just two