public class Solution {
    public long sumEvenNumbers(int n) {
        if (n < 2) return 0;
        long k = n / 2;
        return k * (k + 1);
    }
}
