public class Solution {
    public int minimumLength(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s.charAt(l) == s.charAt(r)) {
            char c = s.charAt(l);
            // Binary search loop to narrow down range
            while (l <= r && s.charAt(l) == c) l++;
            // Binary search loop to narrow down range
            while (l <= r && s.charAt(r) == c) r--;
        }
        return r - l + 1;
    }
}