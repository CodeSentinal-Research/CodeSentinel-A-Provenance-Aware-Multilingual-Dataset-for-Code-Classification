#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    void waveSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (i > 0 && arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
            }
            if (i < n - 1 && arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
};