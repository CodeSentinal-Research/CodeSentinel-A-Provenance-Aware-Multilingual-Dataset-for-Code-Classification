#include <vector>
#include <set>
class Solution {
public:
    std::vector<int> findUnion(std::vector<int>& a, std::vector<int>& b) {
        std::set<int> s(a.begin(),a.end());
        s.insert(b.begin(),b.end());
        return std::vector<int>(s.begin(),s.end());
    }
};
