import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer>[] dp = new Map[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = new HashMap<>();
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                if (diff < Integer.MIN_VALUE || diff > Integer.MAX_VALUE) continue;
                int d = (int)diff;
                int prev = dp[j].getOrDefault(d, 0);
                dp[i].put(d, dp[i].getOrDefault(d, 0) + prev + 1);
                count += prev;
            }
        }
        System.out.println(count);
    }
}
