import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        String pattern = sc.next();
        int m = text.length();
        int n = pattern.length();
        
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (pattern.charAt(j - 1) == '*') dp[0][j] = dp[0][j - 2];
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pattern.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (text.charAt(i - 1) == pattern.charAt(j - 2) || pattern.charAt(j - 2) == '.'));
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (text.charAt(i - 1) == pattern.charAt(j - 1) || pattern.charAt(j - 1) == '?');
                }
            }
        }
        System.out.println(dp[m][n] ? "YES" : "NO");
    }
}
