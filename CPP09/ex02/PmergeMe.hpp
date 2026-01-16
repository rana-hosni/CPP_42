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
#include <ctime>




template<typename T>
void printContainer(const T &container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Accept any callable (function pointer or function object) that takes T&
// template<typename Func, typename T>
// double calculateTime(Func sortFunction, T &container) {
//     clock_t start = clock();
//     sortFunction(container, 0); // assuming sortFunction takes container and an int reference for comparisons
//     clock_t end = clock();
//     return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds
// }


bool validateArguments(int argc, char **argv);
void storeNumbers(const char** argv, std::vector<int> &vNumbers, std::deque<int> &dNumbers);

std::vector<int> sortVector(std::vector<int> &vNumbers, int &comparisons);
std::deque<int> sortDeque(std::deque<int> &dNumbers, int &comparisons);
std::vector<int> insertIntoMainChain(std::vector<int> &mainChain, int value, int &comparisons);
std::deque<int> insertIntoMainChain(std::deque<int> &mainChain, int value, int &comparisons);
std::vector<size_t> jacobsthalOrder(std::vector<int> &smallNumbers);
std::deque<size_t> jacobsthalOrder(std::deque<int> &smallNumbers);

#endif