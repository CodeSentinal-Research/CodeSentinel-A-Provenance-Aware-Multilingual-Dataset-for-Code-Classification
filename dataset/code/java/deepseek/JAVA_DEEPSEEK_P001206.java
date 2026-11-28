import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(canWin(arr, n) ? "YES" : "NO");
    }

    private static boolean canWin(int[] arr, int n) {
        int[][] dp = new int[n][n];
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = arr[i];
                } else if (gap == 1) {
                    dp[i][j] = Math.max(arr[i], arr[j]);
                } else {
                    dp[i][j] = Math.max(arr[i] + Math.min(dp[i + 2][j], dp[i + 1][j - 1]),
                            arr[j] + Math.min(dp[i][j - 2], dp[i + 1][j - 1]));
                }
            }
        }
        return dp[0][n - 1] > 0;
    }
}
