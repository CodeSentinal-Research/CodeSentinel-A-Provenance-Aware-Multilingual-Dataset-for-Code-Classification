import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int F0 = scanner.nextInt();
        int F1 = scanner.nextInt();
        int N = scanner.nextInt();

        System.out.println(evaluateRecurrence(A, B, F0, F1, N));
    }

    private static long evaluateRecurrence(int A, int B, int F0, int F1, int N) {
        if (N == 0) {
            return F0;
        }
        if (N == 1) {
            return F1;
        }
        long[] dp = new long[N + 1];
        dp[0] = F0;
        dp[1] = F1;
        for (int i = 2; i <= N; i++) {
            dp[i] = A * dp[i - 1] + B * dp[i - 2];
        }
        return dp[N];
    }
}
