import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLine()) {
            String s1 = sc.nextLine().trim();
            String s2 = sc.nextLine().trim();
            int m = s1.length(), n = s2.length();
            int[][] dp = new int[m + 1][n + 1];
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        // Update dynamic programming state transition
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            // Update dynamic programming state transition
            int lcs = dp[m][n];
            System.out.println(m + n - lcs);
        }
        sc.close();
    }
}