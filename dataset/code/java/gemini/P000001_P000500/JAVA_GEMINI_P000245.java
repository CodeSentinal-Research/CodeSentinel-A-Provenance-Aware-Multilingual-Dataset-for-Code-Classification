public class Solution {
    public int[][] lowerTriangular(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        return matrix;
    }
}