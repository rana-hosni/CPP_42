#include "PmergeMe.hpp"
#include <math.h>

bool validateArguments(int argc, char **argv){
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                return false;
            }
        }
        try {
            std::istringstream ss(arg);
            int num;
            ss >> num;
            if (ss.fail() || !ss.eof()) {
                return false;
            }
            if (num < 0 || num > INT_MAX) {
                return false;
            }
        } catch (const std::out_of_range&) {
            return false;
        }
    }
    return true;
}

void storeNumbers(const char** argv, std::vector<int> &vNumbers, std::deque<int> &dNumbers){
    for (int i = 1; argv[i] != NULL; i++) {
        int num = std::atoi(argv[i]);
        vNumbers.push_back(num);
        dNumbers.push_back(num);
    }
}

std::vector<int> sortVector(std::vector<int> &vNumbers){
    // step 1: make pairs
    if (vNumbers.size() <= 1) {
        return vNumbers;
    }
    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vNumbers.size(); i += 2) {
        // Keep pairs as vectors by wrapping them in groups of one element
        if (vNumbers[i] < vNumbers[i + 1]) {
            pairs.push_back(std::make_pair(vNumbers[i], vNumbers[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vNumbers[i + 1], vNumbers[i]));
        }
    }

    int leftover = -1;
    if (vNumbers.size() % 2 != 0) {
        leftover = vNumbers.back();
    }

    std::vector<int> bigNumbers;

    // std::cout << "Big numbers before sorting: ";
    for (size_t i = 0; i < pairs.size(); i++) {
        // std::cout << pairs[i].second << " ";
        bigNumbers.push_back(pairs[i].second);
    }

    // std::cout << std::endl;
    std::vector<int> mainChain = sortVector(bigNumbers);

    std::vector<int> smallNumbers;
    for (size_t i = 0; i < pairs.size(); i++) {
        smallNumbers.push_back(pairs[i].first);
    }
    
    if (leftover != -1) {
        smallNumbers.push_back(leftover);
    }
    std::vector<size_t> order = jacobsthalOrder(smallNumbers);

    for (size_t i = 0; i < order.size(); i++) {
        mainChain = insertIntoMainChain(mainChain, smallNumbers[order[i]]);
    }
    return mainChain;
}

// J(n) = J(n-1) + 2*J(n-2)

std::vector<size_t> jacobsthalOrder(std::vector<int>& smallNumbers) {
    size_t n = smallNumbers.size();
    std::vector<size_t> order;
    if (n == 0) 
        return order;
    
    std::vector<bool> used(n, false);
    size_t j0 = 0; // J(0)
    size_t j1 = 1; // J(1)
    while (j1 < n) {
        if (!used[j1]) {
            order.push_back(j1);
            used[j1] = true;
        }
        size_t next = j1 + 2 * j0; // J(n) = J(n-1) + 2*J(n-2)
        j0 = j1;
        j1 = next;
    }
    for (size_t i = n; i-- > 0;) {
        if (!used[i]) {
            order.push_back(i);
        }
    }
    // printContainer(order);
    return order;
}

std::vector<int> insertIntoMainChain(std::vector<int> &mainChain, int value){
    size_t left = 0;
    size_t right = mainChain.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }

    }
    mainChain.insert(mainChain.begin() + left, value);
    return mainChain;
}

// DEQUE IMPLEMENTATION
std::deque<int> sortDeque(std::deque<int> &dNumbers){
      if (dNumbers.size() <= 1) {
        return dNumbers;
    }
    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < dNumbers.size(); i += 2) {
        // Keep pairs as vectors by wrapping them in groups of one element
        if (dNumbers[i] < dNumbers[i + 1]) {
            pairs.push_back(std::make_pair(dNumbers[i], dNumbers[i + 1]));
        } else {
            pairs.push_back(std::make_pair(dNumbers[i + 1], dNumbers[i]));
        }
    }

    int leftover = -1;
    if (dNumbers.size() % 2 != 0) {
        leftover = dNumbers.back();
    }

    std::deque<int> bigNumbers;

    // std::cout << "Big numbers before sorting: ";
    for (size_t i = 0; i < pairs.size(); i++) {
        bigNumbers.push_back(pairs[i].second);
    }

    // std::cout << std::endl;
    std::deque<int> mainChain = sortDeque(bigNumbers);

    std::deque<int> smallNumbers;
    for (size_t i = 0; i < pairs.size(); i++) {
        smallNumbers.push_back(pairs[i].first);
    }
    
    if (leftover != -1) {
        smallNumbers.push_back(leftover);
    }
    std::deque<size_t> order = jacobsthalOrder(smallNumbers);

    for (size_t i = 0; i < order.size(); i++) {
        mainChain = insertIntoMainChain(mainChain, smallNumbers[order[i]]);
    }
    return mainChain;
}

std::deque<size_t> jacobsthalOrder(std::deque<int>& smallNumbers) {
    size_t n = smallNumbers.size();
    std::deque<size_t> order;
    if (n == 0) 
        return order;
    
    std::deque<bool> used(n, false);
    size_t j0 = 0; // J(0)
    size_t j1 = 1; // J(1)
    while (j1 < n) {
        if (!used[j1]) {
            order.push_back(j1);
            used[j1] = true;
        }
        size_t next = j1 + 2 * j0; // J(n) = J(n-1) + 2*J(n-2)
        j0 = j1;
        j1 = next;
    }
    for (size_t i = n; i-- > 0;) {
        if (!used[i]) {
            order.push_back(i);
        }
    }
    // printContainer(order);
    return order;
}

std::deque<int> insertIntoMainChain(std::deque<int> &mainChain, int value){
    size_t left = 0;
    size_t right = mainChain.size();
    int counter = 0;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
        counter++;
    }
    std::cout << "Number of iterations in binary search: " << counter << std::endl;
    mainChain.insert(mainChain.begin() + left, value);
    return mainChain;
}