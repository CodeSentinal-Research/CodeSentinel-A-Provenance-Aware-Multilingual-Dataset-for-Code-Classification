public class Solution {
    public boolean isHarshad(int n) {
        if (n <= 0) return false;
        int temp = n, sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return n % sum == 0;
    }
}
