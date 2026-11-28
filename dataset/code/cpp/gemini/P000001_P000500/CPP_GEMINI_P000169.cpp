#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstRepeated(std::vector<int>& arr) {
        std::unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        for (size_t i = 0; i < arr.size(); i++) {
            if (freq[arr[i]] > 1) return (int)i + 1;
        }
        return -1;
    }
};