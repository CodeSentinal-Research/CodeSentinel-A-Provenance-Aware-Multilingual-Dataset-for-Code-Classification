import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] grid = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        
        int[][][] dp = new int[N][N][N];
        for (int[][] layer : dp) {
            for (int[] row : layer) Arrays.fill(row, -1);
        }
        
        System.out.println(cherryPickup(grid, 0, 0, 0, dp));
    }
    
    static int cherryPickup(int[][] grid, int r1, int c1, int r2, int[][][] dp) {
        int N = grid.length;
        int c2 = r1 + c1 - r2;
        
        if (r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
        
        if (r1 == N - 1 && c1 == N - 1) {
            return grid[r1][c1];
        }
        
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        
        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) {
            cherries += grid[r2][c2];
        }
        
        int maxNext = Integer.MIN_VALUE;
        maxNext = Math.max(maxNext, cherryPickup(grid, r1 + 1, c1, r2 + 1, dp));
        maxNext = Math.max(maxNext, cherryPickup(grid, r1 + 1, c1, r2, dp));
        maxNext = Math.max(maxNext, cherryPickup(grid, r1, c1 + 1, r2 + 1, dp));
        maxNext = Math.max(maxNext, cherryPickup(grid, r1, c1 + 1, r2, dp));
        
        dp[r1][c1][r2] = cherries + maxNext;
        return dp[r1][c1][r2];
    }
}
