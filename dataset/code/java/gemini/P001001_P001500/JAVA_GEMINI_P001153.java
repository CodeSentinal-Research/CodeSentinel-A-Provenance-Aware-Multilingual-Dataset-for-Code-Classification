public class Solution {
    private int count = 0;

    // Calculates modular exponentiation (base^exp % mod) efficiently.
    private void expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            count++;
            l--;
            r++;
        }
    }

    public int countSubstrings(String s) {
        count = 0;
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return count;
    }
}