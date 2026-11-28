#include <vector>
#include <unordered_set>

class Solution {
public:
    int NumberofElementsInIntersection(std::vector<int>& a, std::vector<int>& b, int n, int m) {
        std::unordered_set<int> setA(a.begin(), a.end());
        std::unordered_set<int> inter;
        for (int x : b) {
            if (setA.count(x)) inter.insert(x);
        }
        return inter.size();
    }
};