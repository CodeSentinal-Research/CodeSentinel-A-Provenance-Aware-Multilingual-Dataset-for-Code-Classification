import java.util.*;

public class Main {
    static int N, M;
    static String[] stickers;
    static String target;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();
        stickers = new String[N];
        for (int i = 0; i < N; i++) {
            stickers[i] = sc.nextLine();
        }
        M = sc.nextInt();
        sc.nextLine();
        target = sc.nextLine();
        dp = new int[N][target.length() + 1];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }
        System.out.println(solve(0, 0));
    }

    static int solve(int idx, int tidx) {
        if (tidx == target.length()) {
            return 0;
        }
        if (idx == N) {
            return Integer.MAX_VALUE;
        }
        if (dp[idx][tidx] != -1) {
            return dp[idx][tidx];
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < stickers[idx].length(); i++) {
            res = Math.min(res, solve(idx, tidx + 1));
        }
        return dp[idx][tidx] = res + 1;
    }
}
