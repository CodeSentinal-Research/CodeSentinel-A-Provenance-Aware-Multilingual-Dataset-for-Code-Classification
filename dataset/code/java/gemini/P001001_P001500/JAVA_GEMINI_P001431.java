import java.util.*;

public class Solution {
    public int similarPairs(String[] words) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;

        for (String w : words) {
            int mask = 0;
            for (char c : w.toCharArray()) mask |= (1 << (c - 'a'));
            int prev = map.getOrDefault(mask, 0);
            ans += prev;
            map.put(mask, prev + 1);
        }
        return ans;
    }
}