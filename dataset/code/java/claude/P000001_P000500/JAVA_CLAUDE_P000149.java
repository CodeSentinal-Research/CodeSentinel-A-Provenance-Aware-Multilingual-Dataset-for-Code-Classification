public class Solution {
    public int rowWithMax1s(int[][] matrix) {
        int maxRow = -1, maxCount = -1;
        for (int i = 0; i < matrix.length; i++) {
            int cnt = 0;
            for (int x : matrix[i]) cnt += x;
            if (cnt > maxCount) { maxCount = cnt; maxRow = i; }
        }
        return maxRow;
    }
}
