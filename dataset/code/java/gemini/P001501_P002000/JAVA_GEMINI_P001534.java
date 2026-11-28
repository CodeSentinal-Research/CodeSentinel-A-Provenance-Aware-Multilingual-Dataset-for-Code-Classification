import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character, Integer> count = new HashMap<>();
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            count.put(c, count.getOrDefault(c, 0) + 1);
            while (count.size() > 2) {
                char left = s.charAt(l);
                count.put(left, count.get(left) - 1);
                if (count.get(left) == 0) count.remove(left);
                l++;
            }
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}