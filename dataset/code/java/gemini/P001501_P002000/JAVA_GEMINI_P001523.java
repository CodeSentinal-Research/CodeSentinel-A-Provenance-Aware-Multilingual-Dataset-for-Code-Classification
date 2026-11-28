import java.util.*;

public class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxDq = new ArrayDeque<>();
        Deque<Integer> minDq = new ArrayDeque<>();
        int l = 0;

        for (int num : nums) {
            while (!maxDq.isEmpty() && num > maxDq.peekLast()) maxDq.pollLast();
            while (!minDq.isEmpty() && num < minDq.peekLast()) minDq.pollLast();
            maxDq.offerLast(num);
            minDq.offerLast(num);

            if (maxDq.peekFirst() - minDq.peekFirst() > limit) {
                if (maxDq.peekFirst() == nums[l]) maxDq.pollFirst();
                if (minDq.peekFirst() == nums[l]) minDq.pollFirst();
                l++;
            }
        }
        return nums.length - l;
    }
}