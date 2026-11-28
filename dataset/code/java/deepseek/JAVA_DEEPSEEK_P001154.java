import java.util.Scanner;

public class Main {
    private static int[][] dp;
    private static int[] size;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            size[i] = scanner.nextInt();
        }
        dp = new int[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(minMultiplications(1, n));
    }

    private static int minMultiplications(int start, int end) {
        if (start == end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int min = Integer.MAX_VALUE;
        for (int k = start; k < end; k++) {
            int temp = minMultiplications(start, k) + minMultiplications(k + 1, end) + size[start] * size[k + 1] * size[end];
            if (temp < min) {
                min = temp;
            }
        }
        dp[start][end] = min;
        return min;
    }
}
