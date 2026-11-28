import java.util.*;

public class Solution {
    public int lenOfLongSubarr(int[] arr, int k) {
        Map<Long, Integer> map = new HashMap<>();
        long curSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.length; i++) {
            curSum += arr[i];
            if (curSum == k) {
                maxLen = i + 1;
            } else if (map.containsKey(curSum - k)) {
                maxLen = Math.max(maxLen, i - map.get(curSum - k));
            }
            if (!map.containsKey(curSum)) {
                map.put(curSum, i);
            }
        }
        return maxLen;
    }
}