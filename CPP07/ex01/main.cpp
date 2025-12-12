#include "iter.hpp"

int main(){
    int intArray[] = {1, 2, 3, 4, 5};
    const float fArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
    std::string strArray[] = {"Hello", "This", "Is", "42", "School"};
    const size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    const size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
    const size_t fArrayLength = sizeof(fArray) / sizeof(fArray[0]);

    std::cout << "-----------INTEGER--------------" << std::endl;
    std::cout << "Integer Array:" << std::endl;
    iter(intArray, intArrayLength, printElement);
    std::cout << "------INCREMENT----------" << std::endl;
    iter(intArray, intArrayLength, incrementElement);
    iter(intArray, intArrayLength, printElement);
    std::cout << "-----------FLOAT--------------" << std::endl;
    std::cout << "Float Array:" << std::endl;
    iter(fArray, fArrayLength, printElement);
    // iter(fArray, fArrayLength, incrementElement); // This line will cause a compilation error since fArray is const
    std::cout << "----------STRING---------------" << std::endl;
    std::cout << "String Array:" << std::endl;
    iter(strArray, strArrayLength, printElement);
    return 0;
}