#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumIS(std::vector<int>& arr, int n) {
        std::vector<int> msis = arr;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                    msis[i] = msis[j] + arr[i];
                }
            }
        }
        return *std::max_element(msis.begin(), msis.end());
    }
};