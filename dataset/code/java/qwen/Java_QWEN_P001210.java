import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] coins = new int[n];
        for(int i=0; i<n; i++) coins[i] = sc.nextInt();
        
        int[][] dp = new int[n][n];
        for(int len=1; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(i == j) dp[i][j] = coins[i];
                else {
                    int pickLeft = coins[i] + Math.min(dp[i+2][j], dp[i+1][j-1]);
                    int pickRight = coins[j] + Math.min(dp[i][j-2], dp[i+1][j-1]);
                    dp[i][j] = Math.max(pickLeft, pickRight);
                }
            }
        }
        System.out.println(dp[0][n-1]);
    }
}
