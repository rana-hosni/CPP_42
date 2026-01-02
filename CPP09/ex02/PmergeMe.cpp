#include "PmergeMe.hpp"

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
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vNumbers.size(); i += 2) {
        if (vNumbers[i] < vNumbers[i + 1]) {
            pairs.push_back(std::make_pair(vNumbers[i], vNumbers[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vNumbers[i + 1], vNumbers[i]));
        }
    }
    if (vNumbers.size() % 2 != 0) {
        pairs.push_back(std::make_pair(vNumbers.back(), INT_MAX));
    }
    // Step 2: Build the main chain
    std::vector<int> mainChain = builtMainChain(pairs);
    if (mainChain.size() > 1) {
        mainChain = sortVector(mainChain);   // recursion here
    }
    // if (mainChain.size() == vNumbers.size()/ 2 || (vNumbers.size() % 2 != 0 && mainChain.size() == vNumbers.size() / 2 + 1)) {
    //     return;
    // }
    std::cout << "Pairs after sorting: ";
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    // std::cout << std::endl;
    return mainChain;
}

std::vector<int> builtMainChain(std::vector<std::pair<int, int> > &pairs){
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }
    std::cout << "Main chain before sorting: ";
    printContainer(mainChain);
    // Sort main chain
    return mainChain;
}


// void sortVector(std::vector<int> &vNumbers){
//     int n = vNumbers.size();
//     std::vector<int> right;
//     std::vector<int> left;
//     if (n <= 1)
//         return;
//     for (int i = 0; i < n / 2; i++)
//         left.push_back(vNumbers[i]);
//     for (int i = n / 2; i < n; i++)
//         right.push_back(vNumbers[i]);
//     sortVector(left);
//     sortVector(right);
//     vNumbers.resize(left.size() + right.size());
//     mergeVectors(left, right, vNumbers);
// }

// void mergeVectors(std::vector<int> &left, std::vector<int> &right, std::vector<int> &merged) {
//     size_t i = 0, j = 0, k = 0;
//     while (i < left.size() && j < right.size()) {
//         if (left[i] < right[j]) {
//             merged[k++] = left[i++];
//         } else {
//             merged[k++] = right[j++];
//         }
//     }
//     while (i < left.size()) {
//         merged[k++] = left[i++];
//     }
//     while (j < right.size()) {
//         merged[k++] = right[j++];
//     }
// }

// void sortDeque(std::deque<int> &dNumbers){
//     int n = dNumbers.size();
//     std::deque<int> right;
//     std::deque<int> left;
//     if (n <= 1)
//         return;
//     for (int i = 0; i < n / 2; i++)
//         left.push_back(dNumbers[i]);
//     for (int i = n / 2; i < n; i++)
//         right.push_back(dNumbers[i]);
//     sortDeque(left);
//     sortDeque(right);
//     dNumbers.resize(left.size() + right.size());
//     mergeDeques(left, right, dNumbers);
// }

// void mergeDeques(std::deque<int> &left, std::deque<int> &right, std::deque<int> &merged) {
//     size_t i = 0, j = 0, k = 0;
//     while (i < left.size() && j < right.size()) {
//         if (left[i] < right[j]) {
//             merged[k++] = left[i++];
//         } else {
//             merged[k++] = right[j++];
//         }
//     }
//     while (i < left.size()) {
//         merged[k++] = left[i++];
//     }
//     while (j < right.size()) {
//         merged[k++] = right[j++];
//     }
// }

