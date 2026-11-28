import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();

        int[][] matrix = new int[N][M];
        int[][] prefixSum = new int[N + 1][M + 1];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
                prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j] + matrix[i][j];
            }
        }

        int maxSide = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int p = i; p < N; p++) {
                    for (int q = j; q < M; q++) {
                        int side = p - i + 1;
                        int sum = prefixSum[p + 1][q + 1] - prefixSum[i][q + 1] - prefixSum[p + 1][j] + prefixSum[i][j];
                        if (sum <= K && side > maxSide) {
                            maxSide = side;
                        }
                    }
                }
            }
        }

        System.out.println(maxSide);
    }
}
