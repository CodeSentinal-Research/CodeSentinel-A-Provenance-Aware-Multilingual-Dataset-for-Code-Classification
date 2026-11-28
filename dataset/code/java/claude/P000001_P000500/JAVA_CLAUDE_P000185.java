import java.util.*;
public class Solution {
    public int longestSubarrayEqual01(int[] nums) {
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0, -1);
        int prefix = 0, best = 0;
        for (int i = 0; i < nums.length; i++) {
            prefix += (nums[i] == 1) ? 1 : -1;
            if (mp.containsKey(prefix)) best = Math.max(best, i - mp.get(prefix));
            else mp.put(prefix, i);
        }
        return best;
    }
}
