import java.util.Arrays;

public class Solution {
    public int[][] sortMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] temp = new int[m * n];
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) temp[idx++] = matrix[i][j];
        }
        Arrays.sort(temp);
        idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) matrix[i][j] = temp[idx++];
        }
        return matrix;
    }
}