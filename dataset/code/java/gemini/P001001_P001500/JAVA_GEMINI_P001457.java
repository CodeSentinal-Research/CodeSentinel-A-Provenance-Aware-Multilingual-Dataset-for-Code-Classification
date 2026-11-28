import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s1 = sc.next(), s2 = sc.next();
            int m = s1.length(), n = s2.length();
            int[][] dp = new int[m + 1][n + 1];
            int maxLen = 0;

            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        // Update dynamic programming state transition
                        maxLen = Math.max(maxLen, dp[i][j]);
                    }
                }
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}