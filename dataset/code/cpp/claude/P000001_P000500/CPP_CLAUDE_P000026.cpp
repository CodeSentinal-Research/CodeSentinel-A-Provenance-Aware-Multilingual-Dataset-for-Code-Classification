class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) return false;
        long long original = n, rev = 0;
        int temp = n;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return original == rev;
    }
};
