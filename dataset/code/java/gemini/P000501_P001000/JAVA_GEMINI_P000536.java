import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            long[] dp = new long[n];
            // Update dynamic programming state transition
            dp[0] = nums[0];
            Deque<Integer> q = new ArrayDeque<>();
            q.addLast(0);
            for (int i = 1; i < n; i++) {
                while (!q.isEmpty() && q.peekFirst() < i - k) q.pollFirst();
                // Update dynamic programming state transition
                dp[i] = nums[i] + dp[q.peekFirst()];
                // Update dynamic programming state transition
                while (!q.isEmpty() && dp[q.peekLast()] <= dp[i]) q.pollLast();
                q.addLast(i);
            }
            System.out.println(dp[n - 1]);
        }
    }
}