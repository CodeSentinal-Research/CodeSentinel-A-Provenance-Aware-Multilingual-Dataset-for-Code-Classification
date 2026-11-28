import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] maxJumps = new int[n];
        for (int i = 0; i < n; i++) {
            maxJumps[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(canReachLast(maxJumps, n) ? "YES" : "NO");
    }

    private static boolean canReachLast(int[] maxJumps, int n) {
        boolean[] dp = new boolean[n];
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && maxJumps[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
}
