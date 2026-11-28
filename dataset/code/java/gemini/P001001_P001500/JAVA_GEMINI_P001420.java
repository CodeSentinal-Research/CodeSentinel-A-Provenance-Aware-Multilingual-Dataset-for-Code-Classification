import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> dp = new HashMap<>();
        int maxLen = 0;

        for (int x : arr) {
            int len = dp.getOrDefault(x - difference, 0) + 1;
            dp.put(x, len);
            maxLen = Math.max(maxLen, len);
        }
        return maxLen;
    }
}