public class Solution {
    public double sumOfGP(double a, double r, int n) {
        if (r == 1) return a * n;
        return a * (1 - Math.pow(r, n)) / (1 - r);
    }
}
