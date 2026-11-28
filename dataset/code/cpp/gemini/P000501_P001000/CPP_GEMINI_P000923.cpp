#include <algorithm>

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans = 10, uniqueDigits = 9, available = 9;
        for (int i = 2; i <= std::min(n, 10); i++) {
            uniqueDigits *= available;
            ans += uniqueDigits;
            available--;
        }
        return ans;
    }
};