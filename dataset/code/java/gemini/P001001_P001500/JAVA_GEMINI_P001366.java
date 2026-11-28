public class Solution {
    private int dfs(int[][] grid, int r, int c, int count, int empty) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] < 0) return 0;
        if (grid[r][c] == 2) return count == empty + 1 ? 1 : 0;

        int temp = grid[r][c];
        grid[r][c] = -2;

        int paths = dfs(grid, r + 1, c, count + 1, empty) +
                    dfs(grid, r - 1, c, count + 1, empty) +
                    dfs(grid, r, c + 1, count + 1, empty) +
                    dfs(grid, r, c - 1, count + 1, empty);

        grid[r][c] = temp;
        return paths;
    }

    public int uniquePathsIII(int[][] grid) {
        int empty = 0, startR = 0, startC = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    startR = i; startC = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        return dfs(grid, startR, startC, 0, empty);
    }
}