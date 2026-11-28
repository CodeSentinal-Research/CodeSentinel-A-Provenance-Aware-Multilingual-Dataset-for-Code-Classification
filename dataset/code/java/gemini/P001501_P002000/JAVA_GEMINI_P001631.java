import java.util.*;

public class Solution {
    private static int dfs(int[][] grid, int r, int c, int cur, int target, int m, int n) {
        if (r >= m || c >= n) return 0;
        cur += grid[r][c];
        if (r == m - 1 && c == n - 1) return cur == target ? 1 : 0;
        return dfs(grid, r + 1, c, cur, target, m, n) + dfs(grid, r, c + 1, cur, target, m, n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt(), target = sc.nextInt();
            int[][] grid = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) grid[i][j] = sc.nextInt();
            }
            System.out.println(dfs(grid, 0, 0, 0, target, m, n));
        }
        sc.close();
    }
}