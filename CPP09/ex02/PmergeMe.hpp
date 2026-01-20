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



bool validateArguments(int argc, char **argv);
void storeNumbers(const char** argv, std::vector<int> &vNumbers, std::deque<int> &dNumbers);

std::vector<int> sortVector(std::vector<int> &vNumbers, int &comparisons);
// std::vector<int> sortSmall(std::vector<int> &smallNumbers, std::vector<int> &mainChain, std::vector<std::pair<int, int>> &pairs);
std::deque<int> sortDeque(std::deque<int> &dNumbers, int &comparisons);
std::vector<int> insertIntoMainChain(std::vector<int> &mainChain, int value, size_t upperBoundExclusive, int &comparisons);
std::deque<int> insertIntoMainChain(std::deque<int> &mainChain, int value, int &comparisons);
std::vector<int> jacobsthalOrder(int n);
std::deque<size_t> jacobsthalOrder(std::deque<int> &smallNumbers);


#endif