import java.util.Arrays;
public class Solution {
    public int[][] sortMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] flat = new int[m * n];
        int k = 0;
        for (int[] row : matrix) for (int x : row) flat[k++] = x;
        Arrays.sort(flat);
        k = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) matrix[i][j] = flat[k++];
        return matrix;
    }
}
