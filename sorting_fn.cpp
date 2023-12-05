/* #include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> v) {
    
    while (true) {
        int change_count = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] < v[i]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                change_count++;
            }
        }

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
        int min_idx = 0;
        int min = v[i];
        for (int j = 0; j < v.size(); j++) {
            // Find the index of the minimum
            if (v[j] < min) {
                min = v[j];
                min_idx = j;
            }
        v.erase(v.begin() + j);
        v.insert(v.begin(), min);        
        }
    }
    return v;
}

 */