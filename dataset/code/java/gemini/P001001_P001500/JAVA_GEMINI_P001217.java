public class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] cuts = new int[n];
        for (int i = 0; i < n; i++) cuts[i] = i;

        for (int i = 0; i < n; i++) {
            // odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                cuts[r] = (l == 0) ? 0 : Math.min(cuts[r], cuts[l - 1] + 1);
                l--; r++;
            }
            // even length palindrome
            l = i; r = i + 1;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                cuts[r] = (l == 0) ? 0 : Math.min(cuts[r], cuts[l - 1] + 1);
                l--; r++;
            }
        }
        return cuts[n - 1];
    }
}