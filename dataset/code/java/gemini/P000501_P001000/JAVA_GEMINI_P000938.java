public class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int r1 = mat1.length, c1 = mat1[0].length;
        int c2 = mat2[0].length;
        int[][] res = new int[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int k = 0; k < c1; k++) {
                if (mat1[i][k] != 0) {
                    for (int j = 0; j < c2; j++) {
                        if (mat2[k][j] != 0) {
                            res[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
}