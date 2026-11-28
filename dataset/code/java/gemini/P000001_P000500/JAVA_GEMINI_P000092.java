import java.util.Scanner;

public class Solution {
    public static double sumOfAP(double a, double d, int n) {
        if (n <= 0) return 0.0;
        return (n / 2.0) * (2.0 * a + (n - 1) * d);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double a = sc.nextDouble();
            double d = sc.nextDouble();
            int n = sc.nextInt();
            System.out.printf("%.2f\n", sumOfAP(a, d, n));
        }
        sc.close();
    }
}