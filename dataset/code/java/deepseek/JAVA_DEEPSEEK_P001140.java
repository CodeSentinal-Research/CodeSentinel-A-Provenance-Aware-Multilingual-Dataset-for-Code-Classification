import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int W = scanner.nextInt();

        int[] weights = new int[N];
        int[] values = new int[N];

        for (int i = 0; i < N; i++) {
            weights[i] = scanner.nextInt();
        }

        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextInt();
        }

        int[] dp = new int[W + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = W; j >= weights[i - 1]; j--) {
                dp[j] = Math.max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
            }
        }

        System.out.println(dp[W]);
    }
}
