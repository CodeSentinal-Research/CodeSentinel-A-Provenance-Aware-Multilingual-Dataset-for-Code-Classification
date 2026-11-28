#include <vector>
#include <algorithm>

class Solution {
public:
    int findPlatform(std::vector<int>& arr, std::vector<int>& dep, int n) {
        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());

        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                maxPlatforms = std::max(maxPlatforms, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }
};