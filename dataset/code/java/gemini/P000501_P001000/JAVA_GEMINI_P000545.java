import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            // dp[i] stores optimal answer for prefix of length i
            int[] dp = new int[n];
            Deque<Integer> q = new ArrayDeque<>();
            int maxAns = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                while (!q.isEmpty() && q.peekFirst() < i - k) q.pollFirst();
                // Update dynamic programming state transition
                dp[i] = nums[i] + (!q.isEmpty() && dp[q.peekFirst()] > 0 ? dp[q.peekFirst()] : 0);
                // Update dynamic programming state transition
                maxAns = Math.max(maxAns, dp[i]);
                // Update dynamic programming state transition
                while (!q.isEmpty() && dp[q.peekLast()] <= dp[i]) q.pollLast();
                q.addLast(i);
            }
            System.out.println(maxAns);
        }
    }
}