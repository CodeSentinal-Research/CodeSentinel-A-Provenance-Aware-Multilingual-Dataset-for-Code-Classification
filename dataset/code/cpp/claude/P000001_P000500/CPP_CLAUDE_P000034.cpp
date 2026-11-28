class Solution {
public:
    long long sumOddNumbers(int n) {
        if (n < 1) return 0;
        long long k = (n + 1) / 2;
        return k * k;
    }
};
