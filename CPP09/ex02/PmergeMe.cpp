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
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;
    for (size_t i = 0; i + 1 < vNumbers.size(); i += 2) {
        // Keep pairs as vectors by wrapping each int into a single-element vector
        std::vector<int> a(1, vNumbers[i]);
        std::vector<int> b(1, vNumbers[i + 1]);
        if (a[0] < b[0]) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    std::cout << "----------------------------------------"<< std::endl;
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "Pair " << i << ": (" << pairs[i].first[0] << ", " << pairs[i].second[0] << ")" << std::endl;
    }
    std::cout << "----------------------------------------"<< std::endl;


    int leftover = -1;
    if (vNumbers.size() % 2 != 0) {
        leftover = vNumbers.back();
    }

    std::vector<int> bigNumbers;

    std::cout << "Big numbers before sorting: ";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << pairs[i].second[0] << " ";
        bigNumbers.push_back(pairs[i].second[0]);
    }

    std::cout << std::endl;
    std::vector<int> mainChain = sortVector(bigNumbers);
    // TESTING RECURSION
    std::cout << "TESTING RECURSION" << std::endl;
    for (size_t i = 0; i < mainChain.size(); i++) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> smallNumbers;
    for (size_t i = 0; i < pairs.size(); i++) {
        smallNumbers.push_back(pairs[i].first[0]);
    }

    if (leftover != -1) {
        smallNumbers.push_back(leftover);
    }

    return mainChain;
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

