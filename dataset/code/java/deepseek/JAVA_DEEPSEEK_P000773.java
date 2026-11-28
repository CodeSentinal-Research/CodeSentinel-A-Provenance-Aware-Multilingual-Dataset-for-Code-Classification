import java.io.*;
import java.util.*;

public class Main {
    static int[][] dp;
    static int[][] dp2;
    static int[][] min;
    static int[][] max;
    static int[] nums;
    static char[] op;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String exp = br.readLine();
        int n = exp.length() / 2 + 1;
        nums = new int[n];
        op = new char[n - 1];
        for (int i = 0; i < n; i++) {
            nums[i] = exp.charAt(i * 2) - '0';
            if (i != n - 1) {
                op[i] = exp.charAt(i * 2 + 1);
            }
        }
        dp = new int[n][n];
        dp2 = new int[n][n];
        min = new int[n][n];
        max = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
            Arrays.fill(dp2[i], Integer.MAX_VALUE);
            Arrays.fill(min[i], Integer.MAX_VALUE);
            Arrays.fill(max[i], Integer.MIN_VALUE);
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            dp2[i][i] = nums[i];
            min[i][i] = nums[i];
            max[i][i] = nums[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    if (op[k] == '+') {
                        dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                        dp2[i][j] = Math.min(dp2[i][j], dp2[i][k] + dp2[k + 1][j]);
                    } else if (op[k] == '-') {
                        dp[i][j] = Math.max(dp[i][j], dp[i][k] - dp2[k + 1][j]);
                        dp2[i][j] = Math.min(dp2[i][j], dp2[i][k] - dp[k + 1][j]);
                    } else {
                        dp[i][j] = Math.max(dp[i][j], max[i][k] * max[k + 1][j]);
                        dp2[i][j] = Math.min(dp2[i][j], min[i][k] * min[k + 1][j]);
                        max[i][j] = Math.max(max[i][j], max[i][k] * max[k + 1][j]);
                        min[i][j] = Math.min(min[i][j], min[i][k] * min[k + 1][j]);
                    }
                }
            }
        }
        System.out.println(dp2[0][n - 1]);
    }
}
