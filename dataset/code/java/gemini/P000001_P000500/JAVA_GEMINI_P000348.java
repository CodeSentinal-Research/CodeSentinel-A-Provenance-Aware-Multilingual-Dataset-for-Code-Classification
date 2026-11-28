import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int MOD = 1_000_000_007;
            long[][] dp = new long[2][3];
            // Update dynamic programming state transition
            dp[0][0] = 1;
            for (int i = 0; i < n; i++) {
                long[][] next = new long[2][3];
                for (int a = 0; a < 2; a++) {
                    for (int l = 0; l < 3; l++) {
                        // Update dynamic programming state transition
                        long val = dp[a][l];
                        if (val == 0) continue;
                        next[a][0] = (next[a][0] + val) % MOD;
                        if (a == 0) next[1][0] = (next[1][0] + val) % MOD;
                        if (l < 2) next[a][l + 1] = (next[a][l + 1] + val) % MOD;
                    }
                }
                dp = next;
            }
            long total = 0;
            for (int a = 0; a < 2; a++) {
                for (int l = 0; l < 3; l++) total = (total + dp[a][l]) % MOD;
            }
            System.out.println(total);
        }
    }
}