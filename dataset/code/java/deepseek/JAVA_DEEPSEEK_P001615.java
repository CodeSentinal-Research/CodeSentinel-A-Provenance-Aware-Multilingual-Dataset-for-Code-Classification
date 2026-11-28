import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int target = scanner.nextInt();
        int[][] matrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        int count = countSubmatrices(matrix, N, M, target);
        System.out.println(count);
    }

    private static int countSubmatrices(int[][] matrix, int N, int M, int target) {
        int[][] prefixSum = new int[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + matrix[i][j];
            }
        }
        int count = 0;
        for (int i1 = 1; i1 <= N; i1++) {
            for (int j1 = 1; j1 <= M; j1++) {
                for (int i2 = i1; i2 <= N; i2++) {
                    for (int j2 = j1; j2 <= M; j2++) {
                        int sum = prefixSum[i2][j2] - prefixSum[i2][j1 - 1] - prefixSum[i1 - 1][j2] + prefixSum[i1 - 1][j1 - 1];
                        if (sum == target) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
}
