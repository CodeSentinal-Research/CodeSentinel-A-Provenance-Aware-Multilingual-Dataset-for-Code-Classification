#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findTwoElement(std::vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        for (int i = 0; i < n; i++) {
            int val = std::abs(arr[i]);
            if (arr[val - 1] < 0) {
                repeating = val;
            } else {
                arr[val - 1] = -arr[val - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};