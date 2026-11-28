import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Deque<Integer> dq = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                while (!dq.isEmpty() && nums[dq.peekLast()] >= nums[i]) dq.pollLast();
                dq.offerLast(i);

                while (dq.peekFirst() <= i - k) dq.pollFirst();

                if (i >= k - 1) {
                    System.out.print(nums[dq.peekFirst()] + (i == n - 1 ? "" : " "));
                }
            }
            System.out.println();
        }
        sc.close();
    }
}