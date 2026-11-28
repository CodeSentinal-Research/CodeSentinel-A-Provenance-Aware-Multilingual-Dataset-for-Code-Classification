import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);
        int curSum = 0, maxLen = 0;

        for (int i = 0; i < nums.length; i++) {
            curSum += (nums[i] == 1 ? 1 : -1);
            if (seen.containsKey(curSum)) {
                maxLen = Math.max(maxLen, i - seen.get(curSum));
            } else {
                seen.put(curSum, i);
            }
        }
        return maxLen;
    }
}