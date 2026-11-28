#include <string>
#include <algorithm>

class Solution {
public:
    std::string getSmallestString(int n, int k) {
        std::string res(n, 'a');
        k -= n;

        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = std::min(25, k);
            res[i] = 'a' + add;
            k -= add;
        }
        return res;
    }
};