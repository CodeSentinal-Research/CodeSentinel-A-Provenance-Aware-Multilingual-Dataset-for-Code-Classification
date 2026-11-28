import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int[][] dp = new int[n][n];
        
        for(int len=1; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(len == 1) dp[i][j] = 1;
                else {
                    dp[i][j] = len;
                    if(s.charAt(i) == s.charAt(j)) {
                        dp[i][j] = Math.min(dp[i][j], dp[i+1][j-1] == 0 ? 1 : dp[i+1][j-1]);
                    }
                    for(int k=i; k<j; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }
        System.out.println(dp[0][n-1]);
    }
}
