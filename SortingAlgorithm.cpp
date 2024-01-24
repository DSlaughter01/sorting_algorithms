#include "SortingAlgorithm.hpp"

std::vector<int> bubbleSort(std::vector<int> v) {
    
    while (true) {
        int changeCount = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] < v[i]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                changeCount++;
            }
        }

        if (changeCount == 0) {
            return v;
        }
    }  
}

std::vector<int> insertionSort(std::vector<int> v) {

    for (int i = 1; i < v.size(); i++) {
        int current = v[i];
        // Consider all elements before
        for (int j = 0; j < i; j++) {
            if (v[i] < v[j]) {
                // Remove current element and insert it before the j'th element
                v.erase(v.begin() + i);
                v.insert(v.begin() + j, current);
                break;
            }
        }
    }
    return v;
}

std::vector<int> selectionSort(std::vector<int> v) {

    for (int i = 0; i < v.size(); i++) {

        int minIdx = i;
        int minVal = v[i];

        for (int j = i; j < v.size(); j++) {

            // Find the index of the minimum
            if (v[j] < minVal) {
                minIdx = j;
                minVal = v[j];
            }        
        }

        // Swap
        std::swap(v[i], v[minIdx]);

    }

    return v;
}
