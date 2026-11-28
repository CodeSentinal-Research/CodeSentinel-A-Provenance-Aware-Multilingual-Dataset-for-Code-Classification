import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = matrix[n - 1][i];
        
        for (int i = n - 2; i >= 0; i--) {
            int[] newDp = new int[n];
            for (int j = 0; j < n; j++) {
                newDp[j] = matrix[i][j] + Math.max(dp[Math.max(0, j - 1)], Math.max(dp[j], dp[Math.min(n - 1, j + 1)]));
            }
            dp = newDp;
        }
        
        int maxSum = Integer.MIN_VALUE;
        for (int x : dp) maxSum = Math.max(maxSum, x);
        System.out.println(maxSum);
    }
}
