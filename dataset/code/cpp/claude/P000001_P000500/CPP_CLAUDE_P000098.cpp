#include <vector>

class Solution {
public:
    long long sumOfPrimes(int n) {
        if (n < 2) return 0;
        std::vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (long long i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long sum = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) sum += i;
        }
        return sum;
    }
};
