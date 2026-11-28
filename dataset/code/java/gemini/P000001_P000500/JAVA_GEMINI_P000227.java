public class Solution {
    public int maximumSumRectangle(int R, int C, int[][] M) {
        int maxSum = Integer.MIN_VALUE;

        for (int l = 0; l < C; l++) {
            int[] temp = new int[R];
            for (int r = l; r < C; r++) {
                for (int i = 0; i < R; i++) {
                    temp[i] += M[i][r];
                }

                int cur = temp[0], maxSoFar = temp[0];
                for (int i = 1; i < R; i++) {
                    cur = Math.max(temp[i], cur + temp[i]);
                    maxSoFar = Math.max(maxSoFar, cur);
                }

                maxSum = Math.max(maxSum, maxSoFar);
            }
        }
        return maxSum;
    }
}