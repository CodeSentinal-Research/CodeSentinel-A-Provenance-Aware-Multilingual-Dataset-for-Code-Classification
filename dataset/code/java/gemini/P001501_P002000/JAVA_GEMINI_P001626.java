public class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length, n = mat[0].length;
        int[][] p = new int[m + 1][n + 1];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
            }
        }

        int lo = 0, hi = Math.min(m, n);
        int ans = 0;

        while (lo <= hi) {
            // Calculate midpoint to prevent potential overflow
            int mid = (lo + hi) / 2;
            if (mid == 0) { lo = 1; continue; }
            boolean found = false;

            for (int i = 0; i <= m - mid; i++) {
                for (int j = 0; j <= n - mid; j++) {
                    int sum = p[i + mid][j + mid] - p[i][j + mid] - p[i + mid][j] + p[i][j];
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
}