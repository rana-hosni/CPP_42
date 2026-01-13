
// Your program must:

// Parse them ----- OK

// Validate them -- OK

// Store them -- OK

// Sort them -- OK

// Measure time
// ------------------------------------//
// TESTING COMMAND
// ./PmergeMe $(awk 'BEGIN { srand(); for(i=0;i<3000;i++) printf "%d ", int(rand()*100000) }')



#include "PmergeMe.hpp"

// int main()
// {
//     std::vector<int> v;
//     for (int i = 1; i <= 3000; i++) {
//         v.push_back(i);
//     }
//     std::cout << "Small numbers size : " << v.size() << std::endl;
//     std::vector<size_t> order = jacobsthalOrder(v);
//     return 0;
// }

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }
    std::vector<int> vNumbers;
    std::deque<int> dNumbers;
    if (!validateArguments(argc, argv)) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }
    storeNumbers((const char**)argv, vNumbers, dNumbers);
    std::cout << "Before: ";
    printContainer(vNumbers);
    vNumbers = sortVector(vNumbers);
    // sortDeque(dNumbers);
    // double vectorTime = calculateTime(sortVector, vNumbers);
    // double dequeTime = calculateTime(sortDeque, dNumbers);
    
    // PRINTING THE NUMBERS
    std::cout << "After:  ";
    printContainer(vNumbers);
    // std::cout << "Time to process a range of " << vNumbers.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    // std::cout << "Time to process a range of " << dNumbers.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    // Further implementation goes here
    return 0;
}
