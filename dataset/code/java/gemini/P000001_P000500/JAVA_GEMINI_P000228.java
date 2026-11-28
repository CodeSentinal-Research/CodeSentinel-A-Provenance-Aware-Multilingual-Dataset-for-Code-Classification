public class Solution {
    public boolean search(int[][] matrix, int n, int m, int x) {
        int r = 0, c = m - 1;
        while (r < n && c >= 0) {
            if (matrix[r][c] == x) return true;
            else if (matrix[r][c] > x) c--;
            else r++;
        }
        return false;
    }
}