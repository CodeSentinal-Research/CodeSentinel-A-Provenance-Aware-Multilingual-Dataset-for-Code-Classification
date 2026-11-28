public class Solution {
    private int[] expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }
        return new int[]{l + 1, r - 1};
    }

    public String longestPalindrome(String s) {
        if (s == null || s.isEmpty()) return "";
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            int[] p1 = expand(s, i, i);
            int[] p2 = expand(s, i, i + 1);
            if (p1[1] - p1[0] > end - start) {
                start = p1[0]; end = p1[1];
            }
            if (p2[1] - p2[0] > end - start) {
                start = p2[0]; end = p2[1];
            }
        }
        return s.substring(start, end + 1);
    }
}