import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();
        String C = sc.next();
        int m = A.length();
        int n = B.length();
        
        if (m + n != C.length()) {
            System.out.println("NO");
            return;
        }
        
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;
        
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && A.charAt(i - 1) == C.charAt(i - 1);
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && B.charAt(j - 1) == C.charAt(j - 1);
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] && A.charAt(i - 1) == C.charAt(i + j - 1)) ||
                           (dp[i][j - 1] && B.charAt(j - 1) == C.charAt(i + j - 1));
            }
        }
        System.out.println(dp[m][n] ? "YES" : "NO");
    }
}
