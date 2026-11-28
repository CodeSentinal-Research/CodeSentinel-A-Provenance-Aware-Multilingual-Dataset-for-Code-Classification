import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }
        scanner.close();

        int[][] edges = new int[n][2];
        for (int i = 0; i < n; i++) {
            edges[i] = new int[]{scanner.nextInt() - 1, scanner.nextInt() - 1};
        }

        int[][] dp = new int[n][2];
        dp[0][0] = values[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]) + values[i];
            dp[i][1] = dp[i - 1][0] + values[i];
        }

        int maxPath = Math.max(dp[n - 1][0], dp[n - 1][1]);
        System.out.println(maxPath);
    }
}
