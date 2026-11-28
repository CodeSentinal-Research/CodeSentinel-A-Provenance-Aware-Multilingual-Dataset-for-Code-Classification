public class Solution {
    private int dfs(int[][] grid, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0) return 0;
        int gold = grid[r][c];
        grid[r][c] = 0;

        int maxSub = Math.max(
            Math.max(dfs(grid, r + 1, c), dfs(grid, r - 1, c)),
            Math.max(dfs(grid, r, c + 1), dfs(grid, r, c - 1))
        );

        grid[r][c] = gold;
        return gold + maxSub;
    }

    public int getMaximumGold(int[][] grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] > 0) {
                    maxGold = Math.max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
}