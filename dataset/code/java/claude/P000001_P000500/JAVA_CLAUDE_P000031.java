public class Solution {
    public boolean isArmstrong(int n) {
        if (n < 0) return false;
        int original = n, temp = n, digits = 0;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        temp = n;
        long sum = 0;
        while (temp > 0) {
            int d = temp % 10;
            sum += Math.pow(d, digits);
            temp /= 10;
        }
        return sum == original;
    }
}
