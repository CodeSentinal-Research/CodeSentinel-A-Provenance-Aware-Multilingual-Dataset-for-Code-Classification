public class Solution {
    public int rowWithMax1s(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return -1;
        int m = matrix.length, n = matrix[0].length;
        int r = 0, c = n - 1;
        int maxRow = -1;

        while (r < m && c >= 0) {
            if (matrix[r][c] == 1) {
                maxRow = r;
                c--;
            } else {
                r++;
            }
        }
        return maxRow;
    }
}