import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        System.out.println(maxFallingPathSum(matrix));
    }

    private static int maxFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int left = j > 0 ? dp[i + 1][j - 1] : 0;
                int right = j < n - 1 ? dp[i + 1][j + 1] : 0;
                dp[i][j] = matrix[i][j] + Math.max(left, Math.max(right, dp[i + 1][j]));
            }
        }
        int max = 0;
        for (int j = 0; j < n; j++) {
            max = Math.max(max, dp[0][j]);
        }
        return max;
    }
}
