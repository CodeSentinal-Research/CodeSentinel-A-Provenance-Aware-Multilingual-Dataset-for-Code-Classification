import java.util.Arrays;

public class Solution {
    public int[][] sortedMatrix(int N, int[][] Mat) {
        int[] flat = new int[N * N];
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) flat[idx++] = Mat[i][j];
        }
        Arrays.sort(flat);
        idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) Mat[i][j] = flat[idx++];
        }
        return Mat;
    }
}