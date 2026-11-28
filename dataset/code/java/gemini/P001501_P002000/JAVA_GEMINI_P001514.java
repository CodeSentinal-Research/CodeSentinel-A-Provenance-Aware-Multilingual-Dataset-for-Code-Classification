public class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int n = s.length(), ans = 1, l = 0, lastRepeat = 0;

        for (int r = 1; r < n; r++) {
            if (s.charAt(r) == s.charAt(r - 1)) {
                if (lastRepeat > 0) l = lastRepeat;
                lastRepeat = r;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}