class Solution {
public:
    long long nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
        }
        return res;
    }
};
