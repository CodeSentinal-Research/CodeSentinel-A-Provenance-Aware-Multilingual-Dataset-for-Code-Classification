import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int S = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        boolean[] dp = new boolean[S + 1];
        dp[0] = true;
        for (int num : nums) {
            for (int i = S; i >= num; i--) {
                if (dp[i - num]) dp[i] = true;
            }
        }
        System.out.println(dp[S] ? "YES" : "NO");
    }
}
