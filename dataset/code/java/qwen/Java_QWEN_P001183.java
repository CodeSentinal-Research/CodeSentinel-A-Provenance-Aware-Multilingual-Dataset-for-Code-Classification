import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) heights[i] = sc.nextInt();
        
        int[] dp = new int[n];
        dp[0] = 0;
        if (n > 1) dp[1] = Math.abs(heights[1] - heights[0]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(heights[i] - heights[i - 1]),
                             dp[i - 2] + Math.abs(heights[i] - heights[i - 2]));
        }
        System.out.println(dp[n - 1]);
    }
}
