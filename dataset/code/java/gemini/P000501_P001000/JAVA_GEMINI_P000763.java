import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next(), p = scanner.next();
            int n = s.length(), m = p.length();
            boolean[][] dp = new boolean[n + 1][m + 1];
            // Update dynamic programming state transition
            dp[0][0] = true;
            for (int j = 2; j <= m; j += 2) {
                // Update dynamic programming state transition
                if (p.charAt(j - 1) == '*') dp[0][j] = dp[0][j - 2];
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (p.charAt(j - 1) == '*') {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i][j - 2];
                        if (p.charAt(j - 2) == '.' || p.charAt(j - 2) == s.charAt(i - 1)) {
                            // Update dynamic programming state transition
                            dp[i][j] = dp[i][j] || dp[i - 1][j];
                        }
                    } else {
                        if (p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i - 1)) {
                            // Update dynamic programming state transition
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }
                }
            }
            System.out.println(dp[n][m] ? "true" : "false");
        }
    }
}