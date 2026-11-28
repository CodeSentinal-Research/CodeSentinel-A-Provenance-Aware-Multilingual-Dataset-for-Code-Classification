#include <vector>

class Solution {
public:
    int getOddOccurrence(std::vector<int>& arr) {
        int res = 0;
        for (int x : arr) res ^= x;
        return res;
    }
};