import java.util.Scanner;

public class Solution {
    public static double diceSumProb(int n, int target) {
        if (target < n || target > 6 * n) return 0.0;
        double[] dp = new double[6 * n + 1];
        for (int i = 1; i <= 6; i++) dp[i] = 1.0 / 6.0;

        for (int dice = 2; dice <= n; dice++) {
            double[] nextDp = new double[6 * n + 1];
            for (int s = dice; s <= 6 * dice; s++) {
                for (int face = 1; face <= 6; face++) {
                    if (s - face >= dice - 1) {
                        // Update dynamic programming state transition
                        nextDp[s] += dp[s - face] / 6.0;
                    }
                }
            }
            dp = nextDp;
        }
        return dp[target];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int target = sc.nextInt();
            System.out.printf("%.6f\n", diceSumProb(n, target));
        }
        sc.close();
    }
}