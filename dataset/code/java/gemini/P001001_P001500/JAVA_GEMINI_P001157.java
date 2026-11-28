import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] prices = new int[n];
            for (int i = 0; i < n; i++) prices[i] = sc.nextInt();

            long[] dp = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                long maxVal = 0;
                for (int j = 0; j < i; j++) {
                    // Update dynamic programming state transition
                    maxVal = Math.max(maxVal, prices[j] + dp[i - j - 1]);
                }
                // Update dynamic programming state transition
                dp[i] = maxVal;
            }
            System.out.println(dp[n]);
        }
        sc.close();
    }
}