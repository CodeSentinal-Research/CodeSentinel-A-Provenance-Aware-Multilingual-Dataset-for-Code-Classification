import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                Map<Integer, Integer> count = new HashMap<>();
                count.put(0, 1);
                int cur = 0;

                for (int r = 0; r < m; r++) {
                    cur += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                    ans += count.getOrDefault(cur - target, 0);
                    count.put(cur, count.getOrDefault(cur, 0) + 1);
                }
            }
        }
        return ans;
    }
}