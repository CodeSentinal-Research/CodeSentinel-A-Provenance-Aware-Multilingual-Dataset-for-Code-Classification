public class Solution {
    public int countOddDigits(int n) {
        n = Math.abs(n);
        if (n == 0) return 0;
        int count = 0;
        while (n > 0) {
            if ((n % 10) % 2 != 0) count++;
            n /= 10;
        }
        return count;
    }
}
