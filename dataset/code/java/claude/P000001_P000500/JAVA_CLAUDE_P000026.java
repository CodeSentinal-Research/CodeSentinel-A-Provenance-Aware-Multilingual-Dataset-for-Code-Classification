public class Solution {
    public boolean isPalindrome(int n) {
        if (n < 0) return false;
        int original = n, rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return original == rev;
    }
}
