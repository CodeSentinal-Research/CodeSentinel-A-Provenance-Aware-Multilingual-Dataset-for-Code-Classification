import java.util.*;

public class Solution {
    private int backtrack(String s, int idx, Set<String> seen) {
        if (idx == s.length()) return 0;
        int maxCount = 0;
        for (int i = idx + 1; i <= s.length(); i++) {
            String sub = s.substring(idx, i);
            if (!seen.contains(sub)) {
                seen.add(sub);
                maxCount = Math.max(maxCount, 1 + backtrack(s, i, seen));
                seen.remove(sub);
            }
        }
        return maxCount;
    }

    public int maxUniqueSplit(String s) {
        return backtrack(s, 0, new HashSet<>());
    }
}