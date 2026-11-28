public class Solution {
    public int[] diagonalElements(int[][] matrix) {
        int n = matrix.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = matrix[i][i];
        return res;
    }
}
