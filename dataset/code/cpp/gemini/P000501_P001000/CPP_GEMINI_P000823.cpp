#include <vector>

class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        int left = 0, right = (int)arr.size() - 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
    }
};