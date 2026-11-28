import java.util.Scanner;

public class Solution {
    private static double nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        double ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            double p = sc.nextDouble();
            double ans = nCr(n, k) * Math.pow(p, k) * Math.pow(1.0 - p, n - k);
            System.out.printf("%.6f\n", ans);
        }
        sc.close();
    }
}