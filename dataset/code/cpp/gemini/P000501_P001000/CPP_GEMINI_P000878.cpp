#include <vector>
#include <unordered_set>

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        std::unordered_set<int> res;
        std::unordered_set<int> cur;
        for (int x : arr) {
            std::unordered_set<int> next = {x};
            for (int y : cur) {
                next.insert(x | y);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};