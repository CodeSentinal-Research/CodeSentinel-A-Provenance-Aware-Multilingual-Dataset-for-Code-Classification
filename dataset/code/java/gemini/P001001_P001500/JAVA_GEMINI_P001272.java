import java.util.ArrayDeque;
import java.util.Deque;

public class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        // dp table storing optimal subproblem solutions
        int[] dp = new int[n];
        // Update dynamic programming state transition
        dp[0] = nums[0];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);

        for (int i = 1; i < n; i++) {
            while (!q.isEmpty() && q.peekFirst() < i - k) {
                q.pollFirst();
            }
            // Update dynamic programming state transition
            dp[i] = dp[q.peekFirst()] + nums[i];
            // Update dynamic programming state transition
            while (!q.isEmpty() && dp[q.peekLast()] <= dp[i]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return dp[n - 1];
    }
}