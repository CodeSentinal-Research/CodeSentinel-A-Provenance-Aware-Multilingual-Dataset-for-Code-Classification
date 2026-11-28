import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        long threshold = scanner.nextLong();
        long[][] matrix = new long[N][M];
        long[][] prefixSum = new long[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextLong();
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + matrix[i][j];
            }
        }
        int maxSide = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = i + 1; k <= N; k++) {
                    for (int l = j + 1; l <= M; l++) {
                        long sum = prefixSum[k][l] - prefixSum[k][j] - prefixSum[i][l] + prefixSum[i][j];
                        if (sum < threshold) {
                            maxSide = Math.max(maxSide, k - i);
                        }
                    }
                }
            }
        }
        System.out.println(maxSide);
    }
}
