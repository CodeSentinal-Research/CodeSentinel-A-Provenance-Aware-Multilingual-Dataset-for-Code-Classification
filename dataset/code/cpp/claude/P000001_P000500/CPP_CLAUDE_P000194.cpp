#include <vector>
#include <unordered_set>
#include <set>
class Solution {
public:
    std::vector<int> findIntersection(std::vector<int>& a, std::vector<int>& b) {
        std::unordered_set<int> s(a.begin(),a.end());
        std::set<int> res;
        for (int x : b) if (s.count(x)) res.insert(x);
        return std::vector<int>(res.begin(),res.end());
    }
};
