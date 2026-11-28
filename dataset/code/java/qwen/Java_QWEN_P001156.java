import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int E = sc.nextInt();
        int F = sc.nextInt();
        
        int[][] dp = new int[E + 1][F + 1];
        for (int i = 1; i <= E; i++) {
            for (int j = 1; j <= F; j++) {
                dp[i][j] = j;
                for (int k = 1; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], 1 + Math.max(dp[i - 1][k - 1], dp[i][j - k]));
                }
            }
        }
        System.out.println(dp[E][F]);
    }
}
