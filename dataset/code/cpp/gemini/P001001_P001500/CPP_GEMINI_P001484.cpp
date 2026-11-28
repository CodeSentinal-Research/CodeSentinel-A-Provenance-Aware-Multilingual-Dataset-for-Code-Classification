#include <vector>
#include <algorithm>

class Solution {
public:
    int longestMountain(std::vector<int>& arr) {
        int n = arr.size(), ans = 0, base = 0;

        while (base < n) {
            int end = base;
            if (end + 1 < n && arr[end] < arr[end + 1]) {
                while (end + 1 < n && arr[end] < arr[end + 1]) end++;
                if (end + 1 < n && arr[end] > arr[end + 1]) {
                    while (end + 1 < n && arr[end] > arr[end + 1]) end++;
                    ans = std::max(ans, end - base + 1);
                }
            }
            base = std::max(end, base + 1);
        }
        return ans;
    }
};