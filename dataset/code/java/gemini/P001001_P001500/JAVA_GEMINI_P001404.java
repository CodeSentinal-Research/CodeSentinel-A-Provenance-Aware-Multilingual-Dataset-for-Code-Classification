import java.util.*;

public class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        Map<String, Integer> map = new HashMap<>();

        for (int[] row : grid) {
            String s = Arrays.toString(row);
            map.put(s, map.getOrDefault(s, 0) + 1);
        }

        int ans = 0;
        for (int c = 0; c < n; c++) {
            int[] col = new int[n];
            for (int r = 0; r < n; r++) col[r] = grid[r][c];
            ans += map.getOrDefault(Arrays.toString(col), 0);
        }
        return ans;
    }
}