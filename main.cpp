#include "SortingAlgorithm.hpp"

// https://www.geeksforgeeks.org/how-to-return-a-local-array-from-a-cpp-function/

int main() {
    std::vector<int> myVec {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};

    std::cout << "Working ..." << std::endl;

    // Bubble sort
    std::vector<int> sortedBubble = bubbleSort(myVec);

    for (auto& val: sortedBubble)
        std::cout << val << ", ";
    std::cout << "Done" << std::endl;
    
    // Insertion sort
    std::vector<int> sortedInsert = insertionSort(myVec);

    for (auto& val: sortedInsert)
        std::cout << val << ", ";
    std::cout << "Done" << std::endl;

    // Selection sort
    std::vector<int> sortedSelection = selectionSort(myVec);

    for (auto& val: sortedSelection)
        std::cout << val << ", ";
    std::cout << "Done" << std::endl;

    return 0;
}
