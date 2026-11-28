public class Solution {
    public int[][] rotateMatrix(int M, int N, int[][] mat) {
        int row = 0, col = 0;
        int m = M, n = N;

        while (row < m && col < n) {
            if (row + 1 == m || col + 1 == n) break;

            int prev = mat[row + 1][col];

            for (int i = col; i < n; i++) {
                int curr = mat[row][i];
                mat[row][i] = prev;
                prev = curr;
            }
            row++;

            for (int i = row; i < m; i++) {
                int curr = mat[i][n - 1];
                mat[i][n - 1] = prev;
                prev = curr;
            }
            n--;

            if (row < m) {
                for (int i = n - 1; i >= col; i--) {
                    int curr = mat[m - 1][i];
                    mat[m - 1][i] = prev;
                    prev = curr;
                }
                m--;
            }

            if (col < n) {
                for (int i = m - 1; i >= row; i--) {
                    int curr = mat[i][col];
                    mat[i][col] = prev;
                    prev = curr;
                }
                col++;
            }
        }
        return mat;
    }
}