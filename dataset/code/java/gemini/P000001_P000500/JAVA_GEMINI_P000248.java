public class Solution {
    public int[][] sumMatrix(int[][] A, int[][] B) {
        if (A.length != B.length || A[0].length != B[0].length) return new int[0][0];
        int m = A.length, n = A[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = A[i][j] + B[i][j];
            }
        }
        return res;
    }
}