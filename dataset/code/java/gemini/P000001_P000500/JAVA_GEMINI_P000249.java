public class Solution {
    public int[][] multiplyMatrix(int[][] A, int[][] B) {
        if (A[0].length != B.length) return new int[0][0];
        int r1 = A.length, c1 = A[0].length, c2 = B[0].length;
        int[][] res = new int[r1][c2];

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return res;
    }
}