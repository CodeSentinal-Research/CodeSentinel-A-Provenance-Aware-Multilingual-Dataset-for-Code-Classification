import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < nums.length; i++) {
            prefix += nums[i];
            if (map.containsKey(prefix - k)) {
                maxLen = Math.max(maxLen, i - map.get(prefix - k));
            }
            if (!map.containsKey(prefix)) {
                map.put(prefix, i);
            }
        }
        return maxLen;
    }
}