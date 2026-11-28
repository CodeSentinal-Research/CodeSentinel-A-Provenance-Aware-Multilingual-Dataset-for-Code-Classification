import java.util.*;

public class Solution {
    public int minMoves(int[] nums, int k) {
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) p.add(i);
        }
        int n = p.size();
        long[] presum = new long[n + 1];
        for (int i = 0; i < n; i++) presum[i + 1] = presum[i] + p.get(i);

        long ans = Long.MAX_VALUE;
        int radius = (k - 1) / 2;

        for (int i = radius; i < n - k + radius + 1; i++) {
            long right = presum[i + k - radius] - presum[i + 1];
            long left = presum[i] - presum[i - radius];
            ans = Math.min(ans, right - left);
        }

        long offset = (long) radius * (radius + 1);
        if (k % 2 == 0) offset += (radius + 1);
        return (int)(ans - offset);
    }
}