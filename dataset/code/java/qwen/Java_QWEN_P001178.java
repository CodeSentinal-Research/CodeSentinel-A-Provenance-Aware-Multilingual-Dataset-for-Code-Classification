import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int[][] grid = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        
        int[] dp = new int[R];
        for (int i = 0; i < R; i++) dp[i] = grid[i][0];
        
        for (int j = 1; j < C; j++) {
            int[] newDp = new int[R];
            newDp[0] = dp[0] + grid[0][j];
            for (int i = 1; i < R; i++) {
                newDp[i] = grid[i][j] + Math.max(dp[i], Math.max(newDp[i - 1], i > 1 ? dp[i - 1] : 0));
            }
            dp = newDp;
        }
        
        int maxGold = 0;
        for (int x : dp) maxGold = Math.max(maxGold, x);
        System.out.println(maxGold);
    }
}
