import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[][] matrix = new int[N][M];
        int[][] prefixSum = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
                prefixSum[i][j] = matrix[i][j];
                if (j > 0) {
                    prefixSum[i][j] += prefixSum[i][j - 1];
                }
                if (i > 0) {
                    prefixSum[i][j] += prefixSum[i - 1][j];
                }
                if (i > 0 && j > 0) {
                    prefixSum[i][j] -= prefixSum[i - 1][j - 1];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(prefixSum[i][j] + " ");
            }
            System.out.println();
        }
    }
}
