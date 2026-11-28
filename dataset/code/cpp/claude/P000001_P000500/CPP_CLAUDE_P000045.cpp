class Solution {
public:
    long long sumOfSquares(int n) {
        return ((long long)n * (n + 1) * (2LL * n + 1)) / 6;
    }
};
