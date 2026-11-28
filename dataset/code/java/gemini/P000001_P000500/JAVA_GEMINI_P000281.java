public class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) return "";
        int[] need = new int[128];
        for (char c : t.toCharArray()) need[c]++;

        int missing = t.length();
        int start = 0, minLen = Integer.MAX_VALUE;
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (need[s.charAt(j)] > 0) missing--;
            need[s.charAt(j)]--;

            if (missing == 0) {
                while (i < j && need[s.charAt(i)] < 0) {
                    need[s.charAt(i)]++;
                    i++;
                }
                if (j - i + 1 < minLen) {
                    start = i;
                    minLen = j - i + 1;
                }
                need[s.charAt(i)]++;
                missing++;
                i++;
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}