import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Power = scanner.nextInt();
        int[] tokens = new int[N];
        for (int i = 0; i < N; i++) {
            tokens[i] = scanner.nextInt();
        }
        System.out.println(maxScore(tokens, N, Power));
    }

    public static int maxScore(int[] tokens, int N, int Power) {
        if (N == 1) {
            return tokens[0] * 2;
        }
        if (N == 2) {
            return Math.max(tokens[0] * 2, tokens[1] * 2);
        }
        int[] dp = new int[N + 1];
        dp[0] = 0;
        dp[1] = tokens[0] * 2;
        dp[2] = Math.max(tokens[0] * 2, tokens[1] * 2);
        for (int i = 3; i <= N; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + tokens[i - 1] * 2);
            dp[i] = Math.max(dp[i], dp[i - 3] + tokens[i - 1] * 2 + tokens[i - 2] * 2);
        }
        return dp[N];
    }
}
