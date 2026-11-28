import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int maxVal = Integer.MIN_VALUE;
            int sum = 0;
            for (int j = 1; j <= k && i - j + 1 >= 1; j++) {
                maxVal = Math.max(maxVal, nums[i - j]);
                sum = Math.max(sum, dp[i - j] + maxVal * j);
            }
            dp[i] = sum;
        }
        System.out.println(dp[n]);
    }
}
