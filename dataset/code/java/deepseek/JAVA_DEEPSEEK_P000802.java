import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        int threshold = scanner.nextInt();

        int maxSideLength = maxSideLengthOfSquare(grid, threshold);
        System.out.println(maxSideLength);
    }

    private static int maxSideLengthOfSquare(int[][] grid, int threshold) {
        int N = grid.length;
        int M = grid[0].length;
        int[][] prefixSum = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        for (int k = Math.min(N, M); k >= 1; k--) {
            for (int i = k; i <= N; i++) {
                for (int j = k; j <= M; j++) {
                    int sum = prefixSum[i][j] - prefixSum[i - k][j] - prefixSum[i][j - k] + prefixSum[i - k][j - k];
                    if (sum <= threshold) {
                        return k;
                    }
                }
            }
        }

        return 0;
    }
}
