class Solution {
public:
    long long sumEvenSeries(int n) {
        long long k = n / 2;
        return k * (k + 1);
    }
};
