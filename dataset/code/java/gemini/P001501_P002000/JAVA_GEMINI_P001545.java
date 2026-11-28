import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Deque<Integer> maxDq = new ArrayDeque<>();
            Deque<Integer> minDq = new ArrayDeque<>();
            int minDiff = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                while (!maxDq.isEmpty() && nums[maxDq.peekLast()] <= nums[i]) maxDq.pollLast();
                while (!minDq.isEmpty() && nums[minDq.peekLast()] >= nums[i]) minDq.pollLast();
                maxDq.offerLast(i);
                minDq.offerLast(i);

                while (maxDq.peekFirst() <= i - k) maxDq.pollFirst();
                while (minDq.peekFirst() <= i - k) minDq.pollFirst();

                if (i >= k - 1) {
                    minDiff = Math.min(minDiff, nums[maxDq.peekFirst()] - nums[minDq.peekFirst()]);
                }
            }
            System.out.println(minDiff);
        }
        sc.close();
    }
}