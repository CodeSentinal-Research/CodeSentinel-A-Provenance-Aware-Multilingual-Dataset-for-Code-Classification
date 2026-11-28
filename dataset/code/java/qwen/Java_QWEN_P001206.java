import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] piles = new int[n];
        for(int i=0; i<n; i++) piles[i] = sc.nextInt();
        
        int[][] dp = new int[n][n];
        for(int len=1; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(i == j) dp[i][j] = piles[i];
                else {
                    int left = piles[i] - dp[i+1][j];
                    int right = piles[j] - dp[i][j-1];
                    dp[i][j] = Math.max(left, right);
                }
            }
        }
        System.out.println(dp[0][n-1] >= 0 ? "YES" : "NO");
    }
}
