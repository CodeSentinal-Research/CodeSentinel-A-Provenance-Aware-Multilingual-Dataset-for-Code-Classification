import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] intervals = new int[N + 1];
        for (int i = 0; i < N; i++) {
            intervals[i] = scanner.nextInt();
        }
        System.out.println(minTaps(N, intervals));
    }

    public static int minTaps(int N, int[] intervals) {
        int[] dp = new int[N + 2];
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (intervals[i - 1] == 0) {
                dp[i] = 0;
            } else {
                dp[i] = Math.min(dp[i - 1], dp[i - 1] + (intervals[i - 1] + 1) / (intervals[i - 1] + 1));
            }
        }
        int tap = 0;
        for (int i = 1; i <= N; i++) {
            if (dp[i] == 0) {
                tap = -1;
            }
        }
        return tap;
    }
}
