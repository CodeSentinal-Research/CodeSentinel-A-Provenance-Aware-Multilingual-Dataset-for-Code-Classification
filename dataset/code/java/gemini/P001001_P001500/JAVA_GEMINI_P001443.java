import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        Set<Integer> seen = new HashSet<>();
        for (String w : startWords) {
            int mask = 0;
            for (char c : w.toCharArray()) mask |= (1 << (c - 'a'));
            seen.add(mask);
        }

        int ans = 0;
        for (String w : targetWords) {
            int mask = 0;
            for (char c : w.toCharArray()) mask |= (1 << (c - 'a'));
            for (char c : w.toCharArray()) {
                if (seen.contains(mask ^ (1 << (c - 'a')))) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}