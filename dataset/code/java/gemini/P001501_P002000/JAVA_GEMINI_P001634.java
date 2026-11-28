public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int maxSum = Integer.MIN_VALUE;

        for (int l = 0; l < n; l++) {
            int[] rowSum = new int[m];
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][r];

                for (int i = 0; i < m; i++) {
                    int cur = 0;
                    for (int j = i; j < m; j++) {
                        cur += rowSum[j];
                        if (cur <= k) maxSum = Math.max(maxSum, cur);
                    }
                }
            }
        }
        return maxSum;
    }
}