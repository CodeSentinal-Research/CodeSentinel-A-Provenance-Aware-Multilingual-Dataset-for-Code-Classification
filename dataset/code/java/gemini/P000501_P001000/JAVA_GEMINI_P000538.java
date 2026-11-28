import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            long k = scanner.nextLong();
            long[] prefix = new long[n + 1];
            for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
            Deque<Integer> q = new ArrayDeque<>();
            int minLen = n + 1;
            for (int i = 0; i <= n; i++) {
                while (!q.isEmpty() && prefix[i] - prefix[q.peekFirst()] >= k) {
                    minLen = Math.min(minLen, i - q.pollFirst());
                }
                while (!q.isEmpty() && prefix[q.peekLast()] >= prefix[i]) {
                    q.pollLast();
                }
                q.addLast(i);
            }
            System.out.println(minLen <= n ? minLen : -1);
        }
    }
}