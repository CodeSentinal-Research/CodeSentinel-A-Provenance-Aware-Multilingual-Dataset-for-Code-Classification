#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> rank;
        for (size_t i = 0; i < arr2.size(); i++) rank[arr2[i]] = i;

        std::sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            int rA = rank.count(a) ? rank[a] : 10000 + a;
            int rB = rank.count(b) ? rank[b] : 10000 + b;
            return rA < rB;
        });
        return arr1;
    }
};