import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();
        int[][] matrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        System.out.println(maxArea(matrix, N, M, K));
    }

    private static int maxArea(int[][] matrix, int N, int M, int K) {
        int maxArea = 0;
        int[][] sum = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sum[i][j] = matrix[i][j];
                if (i > 0) {
                    sum[i][j] += sum[i - 1][j];
                }
                if (j > 0) {
                    sum[i][j] += sum[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    sum[i][j] -= sum[i - 1][j - 1];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int p = i; p < N; p++) {
                    for (int q = j; q < M; q++) {
                        int area = sum[p][q] - (i > 0 ? sum[i - 1][q] : 0) - (j > 0 ? sum[p][j - 1] : 0) + (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
                        if (area <= K && area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
        return maxArea;
    }
}
