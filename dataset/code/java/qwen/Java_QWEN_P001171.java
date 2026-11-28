import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        
        long[][] dp = new long[R][C];
        for (int i = 0; i < R; i++) dp[i][0] = 1;
        for (int j = 0; j < C; j++) dp[0][j] = 1;
        
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        System.out.println(dp[R - 1][C - 1]);
    }
}
