public class Solution {
    public double[] findRoots(double a, double b, double c) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double r1 = (-b + Math.sqrt(d)) / (2 * a);
            double r2 = (-b - Math.sqrt(d)) / (2 * a);
            return new double[]{Math.max(r1, r2), Math.min(r1, r2)};
        } else if (d == 0) {
            double r = -b / (2 * a);
            return new double[]{r, r};
        }
        return new double[]{};
    }
}
