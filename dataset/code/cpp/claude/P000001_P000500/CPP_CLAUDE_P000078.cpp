#include <vector>

class Solution {
public:
    std::vector<int> convertDays(int totalDays) {
        int years = totalDays / 365;
        int rem = totalDays % 365;
        int weeks = rem / 7;
        int days = rem % 7;
        return {years, weeks, days};
    }
};
