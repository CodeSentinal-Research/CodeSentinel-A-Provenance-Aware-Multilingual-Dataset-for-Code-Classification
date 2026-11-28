#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> primesInRange(int low, int high) {
        if (high < 2) return {};
        std::vector<bool> isPrime(high + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (long long i = 2; i * i <= high; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= high; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        std::vector<int> res;
        for (int i = std::max(2, low); i <= high; i++) {
            if (isPrime[i]) res.push_back(i);
        }
        return res;
    }
};
