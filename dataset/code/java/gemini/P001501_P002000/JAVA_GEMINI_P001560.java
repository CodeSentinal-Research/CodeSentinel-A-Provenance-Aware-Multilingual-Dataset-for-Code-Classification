import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) return "";

        Map<Character, Integer> target = new HashMap<>();
        for (char c : t.toCharArray()) target.put(c, target.getOrDefault(c, 0) + 1);

        int required = target.size();
        int l = 0, formed = 0;
        Map<Character, Integer> window = new HashMap<>();

        int[] ans = {-1, 0, 0};

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);
            window.put(c, window.getOrDefault(c, 0) + 1);

            if (target.containsKey(c) && window.get(c).intValue() == target.get(c).intValue()) {
                formed++;
            }

            // Binary search loop to narrow down range
            while (l <= r && formed == required) {
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                char left = s.charAt(l);
                window.put(left, window.get(left) - 1);
                if (target.containsKey(left) && window.get(left) < target.get(left)) {
                    formed--;
                }
                l++;
            }
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}