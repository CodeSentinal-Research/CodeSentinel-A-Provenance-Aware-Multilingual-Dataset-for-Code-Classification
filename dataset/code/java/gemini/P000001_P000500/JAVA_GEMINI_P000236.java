public class Solution {
    public int findMaxValue(int[][] mat, int N) {
        int[][] maxArr = new int[N][N];
        maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

        int maxV = mat[N - 1][N - 1];
        for (int j = N - 2; j >= 0; j--) {
            maxV = Math.max(maxV, mat[N - 1][j]);
            maxArr[N - 1][j] = maxV;
        }

        maxV = mat[N - 1][N - 1];
        for (int i = N - 2; i >= 0; i--) {
            maxV = Math.max(maxV, mat[i][N - 1]);
            maxArr[i][N - 1] = maxV;
        }

        int maxDiff = Integer.MIN_VALUE;

        for (int i = N - 2; i >= 0; i--) {
            for (int j = N - 2; j >= 0; j--) {
                maxDiff = Math.max(maxDiff, maxArr[i + 1][j + 1] - mat[i][j]);
                maxArr[i][j] = Math.max(mat[i][j], Math.max(maxArr[i + 1][j], maxArr[i][j + 1]));
            }
        }
        return maxDiff;
    }
}