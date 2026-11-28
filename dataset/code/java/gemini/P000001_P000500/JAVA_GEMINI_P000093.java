import java.util.Scanner;

public class Solution {
    public static double sumOfGP(double a, double r, int n) {
        if (n <= 0) return 0.0;
        if (r == 1.0) return a * n;
        return a * (1.0 - Math.pow(r, n)) / (1.0 - r);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double a = sc.nextDouble();
            double r = sc.nextDouble();
            int n = sc.nextInt();
            System.out.printf("%.2f\n", sumOfGP(a, r, n));
        }
        sc.close();
    }
}