public class Solution {
    public long sumOddNumbers(int n) {
        if (n < 1) return 0;
        long k = (n + 1) / 2;
        return k * k;
    }
}
