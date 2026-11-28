class Solution {
public:
    bool isStrong(int n) {
        if (n <= 0) return false;
        int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int temp = n, sum = 0;
        while (temp > 0) {
            sum += fact[temp % 10];
            temp /= 10;
        }
        return sum == n;
    }
};
