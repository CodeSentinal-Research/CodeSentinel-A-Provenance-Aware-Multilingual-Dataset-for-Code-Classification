import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int e = scanner.nextInt(), f = scanner.nextInt();
            int[][] dp = new int[e + 1][f + 1];
            for (int i = 1; i <= e; i++) { dp[i][1] = 1; dp[i][0] = 0; }
            for (int j = 1; j <= f; j++) dp[1][j] = j;
            for (int i = 2; i <= e; i++) {
                for (int j = 2; j <= f; j++) {
                    // Update dynamic programming state transition
                    dp[i][j] = Integer.MAX_VALUE;
                    for (int x = 1; x <= j; x++) {
                        // Update dynamic programming state transition
                        int res = 1 + Math.max(dp[i - 1][x - 1], dp[i][j - x]);
                        // Update dynamic programming state transition
                        dp[i][j] = Math.min(dp[i][j], res);
                    }
                }
            }
            System.out.println(dp[e][f]);
        }
    }
}