#include "Array.hpp"

int main() {
    Array<int> *intArray=  new Array<int>(5);
    Array<std::string> *strArray = new Array<std::string>(3);
    const Array<int> *constIntArray = new Array<int>(2);
    std::cout << "Integer Array Size: " << intArray->size() << std::endl;
    std::cout << "String Array Size: " << strArray->size() << std::endl;
    std::cout << "Const Integer Array Size: " << constIntArray->size() << std::endl;
    try {
        (*intArray)[10] = 42; // This should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught: Index out of bounds" << std::endl;
    }
    try {
        std::cout << (*constIntArray)[-1] << std::endl; // This should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught: Index out of bounds" << std::endl;
    }
    std::cout << "Setting and getting values in Integer Array:" << std::endl;
    for (unsigned int i = 0; i < intArray->size(); i++)
    {
        (*intArray)[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << (*intArray)[i] << std::endl;
    }
    std::cout << "Setting and getting values in String Array:" << std::endl;
    (*strArray)[0] = "Hello";
    (*strArray)[1] = "World";
    (*strArray)[2] = "!";
    for (unsigned int i = 0; i < strArray->size(); i++)
    {
        std::cout << "strArray[" << i << "] = " << (*strArray)[i] << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Testing Copy Constructor and Assignment Operator:" << std::endl;
    Array<int> copyArray(*intArray); // Copy constructor
    Array<int> assignedArray;
    assignedArray = *intArray; // Assignment operator
    std::cout << "Copy Array:" << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++)
    {
        std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
    }
    std::cout << "Assigned Array:" << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
    }  

    std::cout << "----------------------------------------" << std::endl;


    std::cout << "Modifying original Integer Array to check deep copy:" << std::endl;
    for (unsigned int i = 0; i < intArray->size(); i++)
    {
        (*intArray)[i] += 5;
        std::cout << "intArray[" << i << "] = " << (*intArray)[i] << std::endl;
    }
    std::cout << "Copy Array after modifying original:" << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++)
    {
        std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
    }
    std::cout << "Assigned Array after modifying original:" << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
    }   

    std::cout << "----------------------------------------" << std::endl;

    std::cout << " test const correctness:" << std::endl;
    for (unsigned int i = 0; i < constIntArray->size(); i++)
    {
        std::cout << "constIntArray[" << i << "] = " << (*constIntArray)[i] << std::endl;
    }   

    delete intArray;
    delete strArray;
    delete constIntArray;
    return 0;
}