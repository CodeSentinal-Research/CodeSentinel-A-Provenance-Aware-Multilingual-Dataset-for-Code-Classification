import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] points = new int[n][3];
            for (int i = 0; i < n; i++) {
                points[i][0] = sc.nextInt();
                points[i][1] = sc.nextInt();
                points[i][2] = sc.nextInt();
            }

            // dp[i] stores optimal answer for prefix of length i
            int[] dp = points[0].clone();
            for (int i = 1; i < n; i++) {
                int[] newDp = new int[3];
                // Update dynamic programming state transition
                newDp[0] = points[i][0] + Math.max(dp[1], dp[2]);
                // Update dynamic programming state transition
                newDp[1] = points[i][1] + Math.max(dp[0], dp[2]);
                // Update dynamic programming state transition
                newDp[2] = points[i][2] + Math.max(dp[0], dp[1]);
                dp = newDp;
            }
            System.out.println(Math.max(dp[0], Math.max(dp[1], dp[2])));
        }
        sc.close();
    }
}