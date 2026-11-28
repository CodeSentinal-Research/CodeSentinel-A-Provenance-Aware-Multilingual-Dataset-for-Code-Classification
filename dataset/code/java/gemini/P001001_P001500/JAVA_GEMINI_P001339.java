import java.util.*;

public class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> dp = new ArrayList<>();
        dp.add(0);
        int maxLen = 0;

        for (String s : arr) {
            int mask = 0, dup = 0;
            for (char c : s.toCharArray()) {
                int bit = 1 << (c - 'a');
                if ((mask & bit) > 0) {
                    dup = 1;
                    break;
                }
                mask |= bit;
            }
            if (dup > 0) continue;

            int size = dp.size();
            for (int i = 0; i < size; i++) {
                int prev = dp.get(i);
                if ((prev & mask) == 0) {
                    dp.add(prev | mask);
                    maxLen = Math.max(maxLen, Integer.bitCount(prev | mask));
                }
            }
        }
        return maxLen;
    }
}