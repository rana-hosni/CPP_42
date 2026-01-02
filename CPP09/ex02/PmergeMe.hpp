#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <string>
#include <sstream>
#include <climits>
#include <cstdlib>


template<typename T>
void printContainer(const T &container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
double calculateTime(void (*sortFunction)(T &), T &container) {
    clock_t start = clock();
    sortFunction(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds
}

bool validateArguments(int argc, char **argv);
void storeNumbers(const char** argv, std::vector<int> &vNumbers, std::deque<int> &dNumbers);
std::vector<int> sortVector(std::vector<int> &vNumbers);
std::vector<int> builtMainChain(std::vector<std::pair<int, int> > &pairs);
// void mergeVectors(std::vector<int> &left, std::vector<int> &right, std::vector<int> &merged);
// void sortDeque(std::deque<int> &dNumbers);
// void mergeDeques(std::deque<int> &left, std::deque<int> &right, std::deque<int> &merged);




#endif