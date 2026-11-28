import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int[][] nodes = new int[n][2];
        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ");
            nodes[i][0] = Integer.parseInt(line[0]);
            nodes[i][1] = Integer.parseInt(line[1]);
        }

        int[][] dp = new int[n + 1][2];
        dp[0][0] = 0;
        dp[0][1] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nodes[i - 1][1];
        }

        int max = Math.max(dp[n][0], dp[n][1]);
        System.out.println(max);
    }
}
