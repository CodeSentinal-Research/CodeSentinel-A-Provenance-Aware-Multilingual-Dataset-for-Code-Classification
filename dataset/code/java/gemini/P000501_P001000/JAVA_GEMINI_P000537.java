import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            Deque<Integer> q = new ArrayDeque<>();
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int i = 0; i < n; i++) {
                while (!q.isEmpty() && q.peekFirst() < i - k + 1) q.pollFirst();
                while (!q.isEmpty() && nums[q.peekLast()] <= nums[i]) q.pollLast();
                q.addLast(i);
                if (i >= k - 1) {
                    if (!first) sb.append(" ");
                    sb.append(nums[q.peekFirst()]);
                    first = false;
                }
            }
            System.out.println(sb.toString());
        }
    }
}