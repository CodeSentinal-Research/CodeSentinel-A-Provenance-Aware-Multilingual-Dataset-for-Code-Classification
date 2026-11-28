import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] colors = new int[n];
        for (int i = 0; i < n; i++) {
            colors[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxPoints(colors, n));
    }

    private static int maxPoints(int[] colors, int n) {
        int[][] dp = new int[n][n];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                    if (colors[i] == colors[j]) {
                        dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + len * len);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
}
