import java.util.*;

public class Solution {
    public int[] diagonalElements(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new int[0];
        int n = Math.min(matrix.length, matrix[0].length);
        int[] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = matrix[i][i];
        return res;
    }
}