import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long[] dp = new long[n + 1];
            // Update dynamic programming state transition
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    // Update dynamic programming state transition
                    dp[i] += dp[j] * dp[i - 1 - j];
                }
            }
            System.out.println(dp[n]);
        }
        sc.close();
    }
}