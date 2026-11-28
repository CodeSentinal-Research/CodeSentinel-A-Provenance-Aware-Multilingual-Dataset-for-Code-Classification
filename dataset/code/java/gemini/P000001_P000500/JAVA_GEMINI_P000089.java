import java.util.Scanner;

public class Solution {
    public static double sqrtNewton(double n) {
        if (n < 0) throw new IllegalArgumentException();
        if (n == 0 || n == 1) return n;
        double x = n;
        double epsilon = 1e-7;
        while (true) {
            double root = 0.5 * (x + (n / x));
            if (Math.abs(root - x) < epsilon) {
                return root;
            }
            x = root;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double n = sc.nextDouble();
            System.out.printf("%.6f\n", sqrtNewton(n));
        }
        sc.close();
    }
}