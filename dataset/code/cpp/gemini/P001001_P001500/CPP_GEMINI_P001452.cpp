#include <vector>
#include <unordered_set>

class Solution {
    int rev(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countDistinct(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int x : nums) {
            set.insert(x);
            set.insert(rev(x));
        }
        return set.size();
    }
};