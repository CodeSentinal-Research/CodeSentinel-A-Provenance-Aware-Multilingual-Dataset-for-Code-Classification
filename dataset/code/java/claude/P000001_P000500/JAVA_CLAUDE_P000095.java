public class Solution {
    public boolean isNeon(int n) {
        long sq = (long) n * n;
        long sum = 0;
        while (sq > 0) {
            sum += sq % 10;
            sq /= 10;
        }
        return sum == n;
    }
}
