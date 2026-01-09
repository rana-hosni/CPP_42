
// Your program must:

// Parse them ----- OK

// Validate them -- OK

// Store them -- OK

// Sort them

// Measure time
// ------------------------------------//
// TESTING COMMAND
// ./PmergeMe $(awk 'BEGIN { srand(); for(i=0;i<3000;i++) printf "%d ", int(rand()*100000) }')



#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }
    inputVector input;
    // std::vector<int> vNumbers;
    std::deque<int> dNumbers;
    if (!validateArguments(argc, argv)) {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }
    storeNumbers((const char**)argv, input.vNumbers, dNumbers);
    std::cout << "Before: ";
    printContainer(input.vNumbers);

    try{
        std::cout << "Accessing pair.first before sorting: " ;
        std::cout << input.pair.first << " --- " ;
    }
    catch(...){
        std::cout << "Exception caught while accessing pair.first" << std::endl;
    }
    input.vNumbers = sortVector(input.vNumbers);





    // sortDeque(dNumbers);
    // double vectorTime = calculateTime(sortVector, vNumbers);
    // double dequeTime = calculateTime(sortDeque, dNumbers);
    
    // PRINTING THE NUMBERS
    std::cout << "After:  ";
    printContainer(input.vNumbers);
    // std::cout << "Time to process a range of " << vNumbers.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
    // std::cout << "Time to process a range of " << dNumbers.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    // Further implementation goes here
    return 0;
}

// Step 2: Build the main chain

// Take the smaller elements of each pair:

// 2, 1, 4, 3


// These are the “main chain” candidates

// Sort them recursively or via the same method:

// Split [2,1,4,3] into halves: [2,1] and [4,3]

// Sort [2,1] → [1,2]

// Sort [4,3] → [3,4]

// Merge [1,2] and [3,4] → [1,2,3,4]

// ✅ Now the main chain is [1,2,3,4]

// 4️⃣ Step 3: Insert larger elements using binary search

// Take the larger elements of each pair:

// 7, 9, 5, 8


// Insert them one by one into the main chain [1,2,3,4]

// Step 3a: Insert 7

// Use binary search to find the correct position in [1,2,3,4]

// Indexes: 0 1 2 3
// Values : 1 2 3 4


// Compare 7 with middle element (index 1 → 2) → 7 > 2 → search right half

// Compare 7 with middle of right half (index 2 → 3) → 7 > 3 → search right half

// Compare 7 with 4 → 7 > 4 → insert at index 4

// [1, 2, 3, 4, 7]

// Step 3b: Insert 9

// Binary search [1,2,3,4,7] → find position after 7

// Insert → [1,2,3,4,7,9]

// Step 3c: Insert 5

// Binary search [1,2,3,4,7,9]

// Compare with middle → 4 → 5 > 4 → search right half [7,9]

// Compare 5 with 7 → 5 < 7 → insert at index 4

// [1,2,3,4,5,7,9]

// Step 3d: Insert 8

// Binary search [1,2,3,4,5,7,9]

// Compare with middle → 4 → 8 > 4 → right half [5,7,9]

// Compare with middle → 7 → 8 > 7 → right half [9]

// Compare with 9 → 8 < 9 → insert at index 6

// [1,2,3,4,5,7,8,9]


// ✅ Now the array is fully sorted!

// 5️⃣ Visualization (graph style)
// Unsorted:     7  2  9  1  5  4  8  3
// Pairs:        (2,7)(1,9)(4,5)(3,8)
// Smaller elems: 2  1  4  3
// Main chain:   1  2  3  4
// Insert 7 ->   1  2  3  4  7
// Insert 9 ->   1  2  3  4  7  9
// Insert 5 ->   1  2  3  4  5  7  9
// Insert 8 ->   1  2  3  4  5  7  8  9


// Binary search is used during insertion of larger elements, reducing comparisons from scanning linearly

// Smallest elements build the stable main chain

// 6️⃣ Why it’s efficient

// Classic merge sort: always splits halves → ~n log n comparisons

// Ford-Johnson: builds main chain first, inserts larger elements using binary search → fewer comparisons in practice

// Especially efficient for small arrays, which is why 42 asks for this algorithm

// ✅ Key takeaways

// Pair elements → smaller first

// Sort smaller elements recursively → main chain

// Insert larger elements into main chain using binary search

// Result → fully sorted array, fewer comparisons than classical merge sort