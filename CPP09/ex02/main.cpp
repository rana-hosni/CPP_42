
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
    int comparisons = 0;
    clock_t vstart = clock();
    vNumbers = sortVector(vNumbers, comparisons);
    clock_t vend = clock();
    double vectorTime = static_cast<double>(vend - vstart) / CLOCKS_PER_SEC * 1000000; // microseconds
    printContainer(vNumbers);
    std::cout << "Number of comparisons in vector sort: " << comparisons << std::endl;
    comparisons = 0;
    clock_t dstart = clock();
    dNumbers = sortDeque(dNumbers, comparisons);
    clock_t dend = clock();
    double dequeTime = static_cast<double>(dend - dstart) / CLOCKS_PER_SEC * 1000000; // microseconds
    printContainer(dNumbers);
    
    // PRINTING THE NUMBERS

    std::cout << "Time to process a range of " << vNumbers.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dNumbers.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;

    return 0;
}
