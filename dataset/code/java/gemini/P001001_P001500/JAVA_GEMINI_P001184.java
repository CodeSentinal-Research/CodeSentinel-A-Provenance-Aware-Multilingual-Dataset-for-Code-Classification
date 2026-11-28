import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] heights = new int[n];
            for (int i = 0; i < n; i++) heights[i] = sc.nextInt();

            // dp[i] stores optimal answer for prefix of length i
            int[] dp = new int[n];
            Arrays.fill(dp, Integer.MAX_VALUE);
            // Update dynamic programming state transition
            dp[0] = 0;

            for (int i = 1; i < n; i++) {
                for (int j = Math.max(0, i - k); j < i; j++) {
                    // Update dynamic programming state transition
                    dp[i] = Math.min(dp[i], dp[j] + Math.abs(heights[i] - heights[j]));
                }
            }
            System.out.println(dp[n - 1]);
        }
        sc.close();
    }
}