import java.util.*;

public class Main {
    static int[][] dp;
    static int[] nums;
    static int N;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        nums = new int[N];
        dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i < N; i++) {
            nums[i] = sc.nextInt();
        }
        System.out.println(numTrees(0, N - 1));
    }

    static int numTrees(int i, int j) {
        if (i >= j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for (int k = i; k <= j; k++) {
            ans += numTrees(i, k - 1) * numTrees(k + 1, j);
        }
        return dp[i][j] = ans;
    }
}
