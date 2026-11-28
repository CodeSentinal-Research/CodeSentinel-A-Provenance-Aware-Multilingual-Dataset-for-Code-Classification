import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        int sum = 0;
        for (int num : nums) sum += num;
        
        if ((sum + target) % 2 != 0 || Math.abs(target) > sum) {
            System.out.println(0);
            return;
        }
        
        int newTarget = (sum + target) / 2;
        int[] dp = new int[newTarget + 1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = newTarget; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        System.out.println(dp[newTarget]);
    }
}
