#include <vector>
#include <unordered_set>

class Solution {
public:
    int doUnion(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> s(arr1.begin(), arr1.end());
        for (int x : arr2) s.insert(x);
        return s.size();
    }
};