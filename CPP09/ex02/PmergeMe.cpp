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

std::vector<int> sortVector(std::vector<int> &vNumbers, int &comparisons){
    // step 1: make pairs
    if (vNumbers.size() <= 1) {
        return vNumbers;
    }
    std::vector< std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < vNumbers.size(); i += 2) {
        comparisons++;
        if (vNumbers[i] < vNumbers[i + 1]) {
            pairs.push_back(std::make_pair(vNumbers[i], vNumbers[i + 1]));

        } else {
            pairs.push_back(std::make_pair(vNumbers[i + 1], vNumbers[i]));
        }
    }
    std::cout << "total comparisons after pairing: " << comparisons << std::endl;

    //DEBUGGING
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Pairs formed (small, big): ";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
        // std::cout << " at index " << pairStructs[i].index << "; ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    int leftover = -1;
    if (vNumbers.size() % 2 != 0) {
        leftover = vNumbers.back();
    }

    std::vector<int> bigNumbers;

    std::cout << "Big numbers before sorting: ";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << pairs[i].second << " ";
        bigNumbers.push_back(pairs[i].second);
    }

    std::cout << std::endl;
    std::vector<int> mainChain = sortVector(bigNumbers, comparisons);

    std::vector<int> smallNumbers;

    
    for (size_t i = 0 ; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].second) {
                smallNumbers.push_back(pairs[j].first);
                break;
            }
        }
    }
    if (leftover != -1) {
        smallNumbers.push_back(leftover);
    }

    // DEBUGGING OUTPUT
    std::cout << "-----------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "pairs are (" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;
    }

    for (size_t i = 0; i < smallNumbers.size(); i++) {
        std::cout << "Small number matched to main chain " << mainChain[i] << " is " << smallNumbers[i] << std::endl;
    }
    std::cout << " main chain   : ";
    for (size_t i = 0; i < mainChain.size(); i++) {
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    std::cout << " small numbers: ";
    for (size_t i = 0; i < smallNumbers.size(); i++) {
        std::cout << smallNumbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    std::vector<int> order = jacobsthalOrder(smallNumbers.size());

    PairStruct p;
    for (size_t i = 0; i < order.size(); i++) {
        if (smallNumbers[order[i]] == leftover) {
            std::cout << "Inserting leftover small number " << leftover << " at the end of main chain." << std::endl;
            mainChain = insertIntoMainChain(mainChain, leftover, mainChain.size(), comparisons);
            continue;
        }
        p = updatePairStructs(mainChain, pairs, smallNumbers[order[i]]);
        // DEBUGGING OUTPUT
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "Current main chain: ";
        printContainer(mainChain);
        std::cout << "Current small number to insert: " << smallNumbers[order[i]] << std::endl;
        std::cout << "PairStruct to use for insertion: (small: " << p.small << ", big: " << p.big << ", index: " << p.index << ")" << std::endl;



        std::cout << "Inserting small number " << smallNumbers[order[i]] << " before index " << p.index << " (which has value " << p.big << ") into main chain." << std::endl;
        mainChain = insertIntoMainChain(mainChain, smallNumbers[order[i]], p.index, comparisons);
    }
    // int index;
    // int lookupIndex;
    // for (size_t i = 0; i < order.size(); i++) {
    //     // std::cout << "Inserting small number " << smallNumbers[order[i]] << "in index " << index << " into main chain." << std::endl;
    //     for (size_t k = 0 ; k < pairs.size(); k++) {
    //         if (smallNumbers[order[i]] == pairs[k].first) {
    //             lookupIndex = pairs[k].second;
    //             break;
    //         }
    //     }
    //     for (int j = 0; j < static_cast<int>(mainChain.size()); j++) {
    //         if (mainChain[j] == lookupIndex) {
    //             index = j;
    //             break;
    //         }
    //     }
        // std::cout << "Inserting small number " << smallNumbers[order[i]] << " before index " << index << " (which has value " << mainChain[index] << ") into main chain." << std::endl;
    //     mainChain = insertIntoMainChain(mainChain, smallNumbers[order[i]], index, comparisons);
    // }

    
    // if (leftover != -1) {
        
    //     mainChain = insertIntoMainChain(mainChain, leftover, mainChain.size(), comparisons);
    //     std::cout << "Inserting leftover small number " << leftover << " at the end of main chain." << std::endl;
    // }

    return mainChain;
}

// // J(n) = J(n-1) + 2*J(n-2)

std::vector<int> jacobsthalOrder(int n){
    std::vector<int> order; 
    if (n == 0) 
        return order;
    // Jacobsthal numbers: 1, 3, 5, 11, ... 
    int j0 = 1;
    int j1 = 3; 
    order.push_back(1); 
    while (j1 <= n) { 
        for (int i = j1; i > j0; --i) { 
            order.push_back(i); 
        } 
        int next = j1 + 2 * j0; j0 = j1; j1 = next; 
    }
    // tail
    for (int i = n; i > j0; --i) { 
        order.push_back(i); 
    }
    // convert to 0-based
    for (int i = 0; i <static_cast<int>(order.size()); ++i) 
    { --order[i];
    }
    printContainer(order);
    return order; 
}

PairStruct updatePairStructs(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pairs, int smallValue){
    PairStruct p;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (mainChain[i] == pairs[j].second && pairs[j].first == smallValue) {
                p.big = pairs[j].second;
                p.small = pairs[j].first;
                p.index = i;
                return p;
            }
            else {
                continue;
            }
        }
    }
    return p;
}


std::vector<int> insertIntoMainChain(std::vector<int> &mainChain, int value, 
                                     size_t upperBoundExclusive, int &comparisons) {
    std::cout << "Inserting value " << value << " into main chain up to index " 
              << upperBoundExclusive << std::endl;
    
    if (upperBoundExclusive == 0) {
        mainChain.insert(mainChain.begin(), value);
        return mainChain;
    }

    size_t left = 0;
    size_t right = upperBoundExclusive;
    int compBefore = comparisons;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] == value) {
            left = mid;
            break;  // Early exit on exact match
        }
        comparisons++;
        if (mainChain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    mainChain.insert(mainChain.begin() + left, value);
    std::cout << "Insertion made " << (comparisons - compBefore) << " comparisons." << std::endl;
    return mainChain;
}


// DEQUE IMPLEMENTATION
std::deque<int> sortDeque(std::deque<int> &dNumbers, int &comparisons){
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
    std::deque<int> mainChain = sortDeque(bigNumbers, comparisons);

    std::deque<int> smallNumbers;
    for (size_t i = 0; i < pairs.size(); i++) {
        smallNumbers.push_back(pairs[i].first);
    }
    
    if (leftover != -1) {
        smallNumbers.push_back(leftover);
    }
    std::deque<size_t> order = jacobsthalOrder(smallNumbers);

    for (size_t i = 0; i < order.size(); i++) {
        mainChain = insertIntoMainChain(mainChain, smallNumbers[order[i]], comparisons);
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

std::deque<int> insertIntoMainChain(std::deque<int> &mainChain, int value, int &comparisons){
    size_t left = 0;
    size_t right = mainChain.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (mainChain[mid] < value) {
            left = mid + 1;
            comparisons++;
        } else {
            right = mid;
            comparisons++;
        }
        // comparisons++;
    }
    mainChain.insert(mainChain.begin() + left, value);
    return mainChain;
}


