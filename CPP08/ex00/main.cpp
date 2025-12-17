#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }

    std::list<int> strList;
    strList.push_back(50);
    strList.push_back(60);
    strList.push_back(70);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
        
        it = easyfind(vec, 6);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(strList, 60);
        std::cout << "Found: " << *it << std::endl;
        
        it = easyfind(strList, 80);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try{
        std::vector<int> emptyVec;
        std::vector<int>::iterator it = easyfind(emptyVec, 1);
        std::cout << "Found: " << *it << std::endl;
    } catch (const EmptyContainerException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}