import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int[][] dungeon = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dungeon[i][j] = sc.nextInt();
            }
        }
        
        int[][] dp = new int[R][C];
        dp[R - 1][C - 1] = Math.max(1, 1 - dungeon[R - 1][C - 1]);
        
        for (int i = R - 2; i >= 0; i--) {
            dp[i][C - 1] = Math.max(1, dp[i + 1][C - 1] - dungeon[i][C - 1]);
        }
        for (int j = C - 2; j >= 0; j--) {
            dp[R - 1][j] = Math.max(1, dp[R - 1][j + 1] - dungeon[R - 1][j]);
        }
        
        for (int i = R - 2; i >= 0; i--) {
            for (int j = C - 2; j >= 0; j--) {
                int minHealthNext = Math.min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = Math.max(1, minHealthNext - dungeon[i][j]);
            }
        }
        System.out.println(dp[0][0]);
    }
}
