import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int longestWPI(int[] hours) {
        int score = 0, ans = 0;
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < hours.length; i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                ans = i + 1;
            } else {
                seen.putIfAbsent(score, i);
                if (seen.containsKey(score - 1)) {
                    ans = Math.max(ans, i - seen.get(score - 1));
                }
            }
        }
        return ans;
    }
}