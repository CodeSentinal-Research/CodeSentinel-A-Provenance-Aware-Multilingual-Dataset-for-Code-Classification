#include <vector>
class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) l = mid + 1;
            else r = mid;
        }
        return std::vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
