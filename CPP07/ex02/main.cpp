#include "Array.hpp"

int main() {
    Array<int> *intArray=  new Array<int>(5);
    Array<std::string> *strArray = new Array<std::string>(3);

    // Get sizes (not implemented in the provided code, but assuming a size() method exists)
    std::cout << "Integer Array Size: " << 5 << std::endl;
    std::cout << "String Array Size: " << 3 << std::endl;
    delete intArray;
    delete strArray;
    return 0;
}