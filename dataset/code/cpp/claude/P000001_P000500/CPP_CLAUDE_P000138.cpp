#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> mergeSorted(std::vector<int>& a, std::vector<int>& b) {
        std::vector<int> res;
        std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(res));
        return res;
    }
};
