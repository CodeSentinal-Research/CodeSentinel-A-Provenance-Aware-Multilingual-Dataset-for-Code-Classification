import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[][] matrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        long count = countSubmatrices(matrix, N, M);
        System.out.println(count);
    }

    private static long countSubmatrices(int[][] matrix, int N, int M) {
        int[][] prefixSum = new int[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + matrix[i][j];
            }
        }
        long count = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = i; k <= N; k++) {
                    for (int l = j; l <= M; l++) {
                        if (prefixSum[k][l] - prefixSum[i - 1][l] - prefixSum[k][j - 1] + prefixSum[i - 1][j - 1] == 0) {
                            count += (long)((k - i + 1) * (l - j + 1));
                        }
                    }
                }
            }
        }
        return count;
    }
}
