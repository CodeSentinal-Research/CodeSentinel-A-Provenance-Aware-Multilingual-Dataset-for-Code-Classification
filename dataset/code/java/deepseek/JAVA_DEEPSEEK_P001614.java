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
        System.out.println(maxSum(matrix));
    }

    private static int maxSum(int[][] matrix) {
        int N = matrix.length;
        int M = matrix[0].length;
        int[][] sum = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sum[i][j] = matrix[i][j];
                if (i > 0) sum[i][j] += sum[i - 1][j];
                if (j > 0) sum[i][j] += sum[i][j - 1];
                if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
            }
        }
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int currSum = 0;
                for (int k = 0; k < M; k++) {
                    currSum += sum[j][k] - (i > 0 ? sum[i - 1][k] : 0);
                    maxSum = Math.max(maxSum, currSum);
                }
            }
        }
        return maxSum;
    }
}
