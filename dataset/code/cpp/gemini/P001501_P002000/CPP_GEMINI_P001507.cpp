#include <vector>
#include <algorithm>

class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        int n = arr.size();
        int ans = 1, anchor = 0;

        for (int i = 1; i < n; i++) {
            int c = (arr[i - 1] > arr[i]) - (arr[i - 1] < arr[i]);
            if (c == 0) {
                anchor = i;
            } else if (i == n - 1 || c * ((arr[i] > arr[i + 1]) - (arr[i] < arr[i + 1])) != -1) {
                ans = std::max(ans, i - anchor + 1);
                anchor = i;
            }
        }
        return ans;
    }
};