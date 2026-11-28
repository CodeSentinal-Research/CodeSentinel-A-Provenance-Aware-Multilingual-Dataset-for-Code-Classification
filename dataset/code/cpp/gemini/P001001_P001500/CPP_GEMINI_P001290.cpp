#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        std::vector<int> arr = {a, b, c};
        std::sort(arr.begin(), arr.end());
        if (arr[0] + arr[1] <= arr[2]) {
            return arr[0] + arr[1];
        }
        return (a + b + c) / 2;
    }
};