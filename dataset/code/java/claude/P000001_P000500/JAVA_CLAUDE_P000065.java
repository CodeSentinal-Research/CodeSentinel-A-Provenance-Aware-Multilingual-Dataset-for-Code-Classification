public class Solution {
    private long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return Math.abs(a);
    }

    private long lcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        return (Math.abs(a) / gcd(a, b)) * Math.abs(b);
    }

    public long lcmOfThree(int a, int b, int c) {
        return lcm(lcm(a, b), c);
    }
}
