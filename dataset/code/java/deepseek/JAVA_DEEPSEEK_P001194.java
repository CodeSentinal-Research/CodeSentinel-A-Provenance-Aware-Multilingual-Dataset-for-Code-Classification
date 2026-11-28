import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(maxSum(arr, N, K));
    }

    private static int maxSum(int[] arr, int N, int K) {
        int[][] dp = new int[N + 1][K + 1];
        for (int i = 0; i < N + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < K + 1; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i < N + 1; i++) {
            int max = -1;
            for (int j = 1; j < K + 1; j++) {
                if (i <= j) {
                    max = Math.max(max, arr[i - 1] + dp[i - 1][j - 1]);
                }
                dp[i][j] = max;
            }
        }
        return dp[N][K];
    }
}
