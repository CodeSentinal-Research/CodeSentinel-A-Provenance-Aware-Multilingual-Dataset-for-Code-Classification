import java.util.Scanner;

public class Main {
    static int N, K;
    static int[] arr;
    static boolean[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        dp = new boolean[N + 1][K + 1];
        dp[0][0] = true;
        if (arr[0] <= 10 && dp[1][arr[0]]) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean solve(int idx, int sum) {
        if (idx == N) {
            return sum == 0;
        }
        if (dp[idx][sum]) {
            return false;
        }
        dp[idx][sum] = true;
        return solve(idx + 1, sum) || solve(idx + 1, sum + arr[idx]);
    }
}
