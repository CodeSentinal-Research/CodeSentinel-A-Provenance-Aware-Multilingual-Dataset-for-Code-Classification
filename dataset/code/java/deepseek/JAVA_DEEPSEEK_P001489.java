import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Target = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(countSubsequences(arr, N, Target));
    }

    private static long countSubsequences(int[] arr, int N, int Target) {
        long[] dp = new long[Target + 1];
        dp[0] = 1;
        for (int i = 1; i <= Target; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= arr[j]) {
                    dp[i] += dp[i - arr[j]];
                    dp[i] %= (int) (1e9 + 7);
                }
            }
        }
        return dp[Target];
    }
}
