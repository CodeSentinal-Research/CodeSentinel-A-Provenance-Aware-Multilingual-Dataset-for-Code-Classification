import java.util.Scanner;

public class Main {
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int E = sc.nextInt();
        int F = sc.nextInt();
        dp = new int[E + 1][F + 1];
        for (int i = 0; i <= E; i++) {
            for (int j = 0; j <= F; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(solve(E, F));
    }

    static int solve(int e, int f) {
        if (f == 0 || f == 1) {
            return f;
        }
        if (e == 1) {
            return f;
        }
        if (dp[e][f] != -1) {
            return dp[e][f];
        }
        int mn = Integer.MAX_VALUE;
        for (int k = 1; k <= f; k++) {
            int temp = 1 + Math.max(solve(e - 1, k - 1), solve(e, f - k));
            mn = Math.min(mn, temp);
        }
        dp[e][f] = mn;
        return mn;
    }
}
