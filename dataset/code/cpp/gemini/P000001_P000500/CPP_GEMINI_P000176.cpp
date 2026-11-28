#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long findMinDiff(std::vector<long long>& a, long long n, long long m) {
        if (m == 0 || n == 0 || m > n) return 0;
        std::sort(a.begin(), a.end());
        long long minDiff = LLONG_MAX;
        for (long long i = 0; i <= n - m; i++) {
            minDiff = std::min(minDiff, a[i + m - 1] - a[i]);
        }
        return minDiff;
    }
};