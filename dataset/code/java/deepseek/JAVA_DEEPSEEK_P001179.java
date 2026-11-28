import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] dp = new int[N+1][4];
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=3; j++) {
                dp[i][j] = sc.nextInt();
            }
        }
        for(int i=2; i<=N; i++) {
            dp[i][1] += Math.max(dp[i-1][2], dp[i-1][3]);
            dp[i][2] += Math.max(dp[i-1][1], dp[i-1][3]);
            dp[i][3] += Math.max(dp[i-1][1], dp[i-1][2]);
        }
        System.out.println(Math.max(Math.max(dp[N][1], dp[N][2]), dp[N][3]));
    }
}
