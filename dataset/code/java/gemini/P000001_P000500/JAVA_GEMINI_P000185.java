import java.util.*;

public class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int curSum = 0, maxLen = 0;

        for (int i = 0; i < nums.length; i++) {
            curSum += (nums[i] == 1 ? 1 : -1);
            if (map.containsKey(curSum)) {
                maxLen = Math.max(maxLen, i - map.get(curSum));
            } else {
                map.put(curSum, i);
            }
        }
        return maxLen;
    }
}