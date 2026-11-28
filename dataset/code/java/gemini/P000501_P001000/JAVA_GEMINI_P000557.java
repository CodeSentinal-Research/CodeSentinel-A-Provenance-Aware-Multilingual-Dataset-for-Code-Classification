import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int target = scanner.nextInt();
            // dp table storing optimal subproblem solutions
            int[] dp = new int[target + 1];
            for (int t = 1; t <= target; t++) {
                int k = 0;
                while ((1 << k) <= t) k++;
                if (t == (1 << k) - 1) {
                    // Update dynamic programming state transition
                    dp[t] = k;
                    continue;
                }
                // Update dynamic programming state transition
                dp[t] = dp[(1 << k) - 1 - t] + k + 1;
                for (int j = 0; j < k - 1; j++) {
                    // Update dynamic programming state transition
                    dp[t] = Math.min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
                }
            }
            System.out.println(dp[target]);
        }
    }
}