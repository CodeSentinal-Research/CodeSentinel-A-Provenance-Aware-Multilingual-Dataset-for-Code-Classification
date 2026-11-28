import java.util.*;
public class Solution {
    public int[] nextSmallerElement(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i])
                res[stack.pop()] = nums[i];
            stack.push(i);
        }
        return res;
    }
}
