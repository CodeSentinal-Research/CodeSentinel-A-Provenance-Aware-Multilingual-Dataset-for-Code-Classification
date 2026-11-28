public class Solution {
    private static final int[] FACT = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    public boolean isStrong(int n) {
        if (n <= 0) return false;
        int temp = n, sum = 0;
        while (temp > 0) {
            sum += FACT[temp % 10];
            temp /= 10;
        }
        return sum == n;
    }
}
