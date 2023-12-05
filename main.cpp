#include <iostream>
#include <vector>
using namespace std;
// https://www.geeksforgeeks.org/how-to-return-a-local-array-from-a-cpp-function/

vector<int> bubble_sort(vector<int> v) {
    
    while (true) {
        int change_count = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] < v[i]) {      // > gives descending order

                // Switch elements
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                change_count++;
            }
        }

        // If the algorithm passes without changing anything, the vector is sorted
        if (change_count == 0) {
            return v;
        }
    }  
}

vector<int> insertion_sort(vector<int> v) {

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

vector<int> selection_sort(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {

        int min_idx = i;
        int min = v[i];

        for (int j = i; j < v.size(); j++) {
            // Find the index of the minimum
            if (v[j] < min) {
                min = v[j];
                min_idx = j;
            }
        }
        // Remove min and put it on the front of the array
        v.erase(v.begin() + min_idx);
        v.insert(v.begin() + i, min);  // v.insert(v.begin(), min) gives descending order
    }
    return v;
}


vector<int> merge_helper(vector<int> first, vector<int> second) {
    int i = 0;
    int j = 0;
    vector<int> v {};

    // Fill v until one vector is empty
    while(i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            cout << first[i];
            v.push_back(first[i]);
            i++;
        } else {
            v.push_back(second[j]);
            cout << second[j];

            j++;
        }
    }

    // Keep adding elements until both vectors are covered
    while (i < first.size()) {
        v.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        v.push_back(second[j]);
        j++;
    }

    return v;
}

vector<int> merge_sort(vector<int> v) {

    // Split the input in 2
    vector<int> first;
    vector<int> second;

    if (v.size() > 1) {
        for (int i = 0; i < v.size() / 2; i++)
            first.push_back(v[i]);
        for (int i = v.size() / 2; i < v.size(); i++)
            second.push_back(v[i]);
    }
  
    cout << "First half: ";
    for (int i = 0; i < first.size() - 1; i++)
        cout << first[i] << ", ";
    cout << first[first.size() - 1];
    cout << endl;

    cout << "Second half: ";
    for (int i = 0; i < second.size() - 1; i++)
        cout << second[i] << ", ";
    cout << second[second.size() - 1];
    cout << endl;

    first = merge_sort(first);
    second = merge_sort(second); // Never reach this 

    v = merge_helper(first, second);
    
    return v;
}

int main() {
    vector<int> my_vec {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    vector<int> my_vec2 {9, 6, 5, 0, 8};
    vector<int> my_vec3 {2, 7, 1, 3, 4};


    vector<int> sorted_bubble = bubble_sort(my_vec);
    vector<int> sorted_insert = insertion_sort(my_vec);
    vector<int> sorted_merger = merge_sort(my_vec);

    cout << "Working ..." << endl;

    for (int i = 0; i < my_vec.size() - 1; i++) {
        cout << sorted_bubble[i] << ", ";
    }
    cout << sorted_bubble[my_vec.size() - 1] << endl;

    for (int i = 0; i < my_vec.size() - 1; i++) {
        cout << sorted_insert[i] << ", ";
    }
    cout << sorted_insert[my_vec.size() - 1] << endl;

    for (int i = 0; i < my_vec.size() - 1; i++) {
        cout << sorted_merger[i] << ", ";
    }
    cout << sorted_merger[my_vec.size() - 1] << endl;
    cout << "Done" << endl;

    return 0;
}
