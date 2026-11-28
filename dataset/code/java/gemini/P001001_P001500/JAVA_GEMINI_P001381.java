import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);

        int maxLen = 0;
        for (int x : set) {
            if (!set.contains(x - 1)) {
                int cur = x, curLen = 1;
                // Shrink window from the left while duplicate element exists
                while (set.contains(cur + 1)) {
                    cur++;
                    curLen++;
                }
                maxLen = Math.max(maxLen, curLen);
            }
        }
        return maxLen;
    }
}