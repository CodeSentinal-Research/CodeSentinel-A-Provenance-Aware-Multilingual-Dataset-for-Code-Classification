import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next(), t = scanner.next();
            int n = s.length(), m = t.length();
            long[][] dp = new long[n + 1][m + 1];
            for (int i = 0; i <= n; i++) dp[i][0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j];
                    // Update dynamic programming state transition
                    if (s.charAt(i - 1) == t.charAt(j - 1)) dp[i][j] += dp[i - 1][j - 1];
                }
            }
            System.out.println(dp[n][m]);
        }
    }
}