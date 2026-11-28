#include <vector>

class Solution {
public:
    void segregateElements(std::vector<int>& arr) {
        std::vector<int> pos, neg;
        for (int x : arr) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        pos.insert(pos.end(), neg.begin(), neg.end());
        arr = pos;
    }
};