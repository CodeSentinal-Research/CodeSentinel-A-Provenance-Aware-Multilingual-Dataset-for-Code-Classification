#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> res;
        int lowLen = std::to_string(low).length();
        int highLen = std::to_string(high).length();

        for (int len = lowLen; len <= highLen; len++) {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                for (int d = start; d < start + len; d++) {
                    num = num * 10 + d;
                }
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};