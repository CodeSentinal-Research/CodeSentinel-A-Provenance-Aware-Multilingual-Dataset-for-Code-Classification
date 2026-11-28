public class Solution {
    public int findSaddlePoint(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            int minRow = matrix[i][0];
            int colIdx = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minRow) {
                    minRow = matrix[i][j];
                    colIdx = j;
                }
            }

            boolean isSaddle = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][colIdx] > minRow) {
                    isSaddle = false;
                    break;
                }
            }

            if (isSaddle) return minRow;
        }
        return -1;
    }
}