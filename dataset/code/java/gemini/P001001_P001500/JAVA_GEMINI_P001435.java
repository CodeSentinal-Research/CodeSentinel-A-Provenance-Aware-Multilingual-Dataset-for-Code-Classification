import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> c1 = new HashMap<>();
        for (String w : words1) c1.put(w, c1.getOrDefault(w, 0) + 1);

        Map<String, Integer> c2 = new HashMap<>();
        for (String w : words2) c2.put(w, c2.getOrDefault(w, 0) + 1);

        int ans = 0;
        for (String w : c1.keySet()) {
            if (c1.get(w) == 1 && c2.getOrDefault(w, 0) == 1) {
                ans++;
            }
        }
        return ans;
    }
}