import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt(), target = sc.nextInt();
            long MOD = 1000000007;
            long[] dp = new long[target + 1];
            // Update dynamic programming state transition
            dp[0] = 1;

            for (int step = 0; step < n; step++) {
                long[] newDp = new long[target + 1];
                for (int j = 1; j <= target; j++) {
                    for (int face = 1; face <= k; face++) {
                        if (j >= face) {
                            // Update dynamic programming state transition
                            newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                        }
                    }
                }
                dp = newDp;
            }
            System.out.println(dp[target]);
        }
        sc.close();
    }
}