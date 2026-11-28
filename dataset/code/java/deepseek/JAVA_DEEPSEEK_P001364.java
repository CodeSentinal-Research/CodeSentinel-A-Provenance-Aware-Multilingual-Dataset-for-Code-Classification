import java.util.Scanner;

public class Main {
    static int[] arr;
    static int[][] dp;
    static int N, K;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        arr = new int[N];
        dp = new int[N + 1][K + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = -1;
            }
        }

        System.out.println(solve(0, 0));
    }

    static int solve(int idx, int k) {
        if (k == 0) {
            return 0;
        }
        if (idx == N) {
            return Integer.MAX_VALUE;
        }
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int notTake = solve(idx + 1, k);
        int take = arr[idx] + solve(idx + 1, k - 1);

        return dp[idx][k] = Math.min(notTake, take);
    }
}
