import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastPos = new HashMap<>();
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            if (lastPos.containsKey(c) && lastPos.get(c) >= l) {
                l = lastPos.get(c) + 1;
            }
            lastPos.put(c, r);
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}