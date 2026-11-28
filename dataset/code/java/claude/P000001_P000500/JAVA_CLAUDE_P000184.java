import java.util.*;
public class Solution {
    public int longestSubarrayWithSumK(int[] nums, long k) {
        Map<Long,Integer> map = new HashMap<>();
        map.put(0L, -1);
        long prefix = 0;
        int best = 0;
        for (int i = 0; i < nums.length; i++) {
            prefix += nums[i];
            if (map.containsKey(prefix - k))
                best = Math.max(best, i - map.get(prefix - k));
            map.putIfAbsent(prefix, i);
        }
        return best;
    }
}
