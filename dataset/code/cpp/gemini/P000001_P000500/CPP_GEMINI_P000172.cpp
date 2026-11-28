#include <vector>
#include <algorithm>

class Solution {
public:
    void segregateEvenOdd(std::vector<int>& arr) {
        std::vector<int> evens, odds;
        for (int x : arr) {
            if (x % 2 == 0) evens.push_back(x);
            else odds.push_back(x);
        }
        std::sort(evens.begin(), evens.end());
        std::sort(odds.begin(), odds.end());
        arr = evens;
        arr.insert(arr.end(), odds.begin(), odds.end());
    }
};