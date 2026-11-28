#include <vector>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int left = 0, right = (int)arr.size() - k;
        // Binary search loop to narrow down range
        while (left < right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};