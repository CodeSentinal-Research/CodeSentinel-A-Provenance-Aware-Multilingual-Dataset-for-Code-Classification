import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), w = sc.nextInt();
            int[] values = new int[n];
            for (int i = 0; i < n; i++) values[i] = sc.nextInt();
            int[] weights = new int[n];
            for (int i = 0; i < n; i++) weights[i] = sc.nextInt();

            long[] dp = new long[w + 1];
            for (int i = 0; i < n; i++) {
                int wt = weights[i], val = values[i];
                for (int j = wt; j <= w; j++) {
                    // Update dynamic programming state transition
                    dp[j] = Math.max(dp[j], dp[j - wt] + val);
                }
            }
            System.out.println(dp[w]);
        }
        sc.close();
    }
}