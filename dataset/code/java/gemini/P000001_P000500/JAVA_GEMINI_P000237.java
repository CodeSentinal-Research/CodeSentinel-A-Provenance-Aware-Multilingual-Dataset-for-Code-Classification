public class Solution {
    public int[][] rotateMatrix(int N, int M, int K, int[][] Mat) {
        int k = K % M;
        for (int i = 0; i < N; i++) {
            int[] temp = new int[M];
            for (int j = 0; j < M; j++) {
                temp[j] = Mat[i][(j + k) % M];
            }
            Mat[i] = temp;
        }
        return Mat;
    }
}