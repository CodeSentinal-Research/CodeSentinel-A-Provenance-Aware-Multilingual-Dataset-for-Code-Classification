public class Solution {
    private boolean backtrack(String s, int idx, long prev, int count) {
        if (idx == s.length()) return count >= 2;
        for (int i = idx + 1; i <= s.length(); i++) {
            long val;
            try {
                val = Long.parseLong(s.substring(idx, i));
            } catch (Exception e) {
                break;
            }
            if (prev == -1 || val == prev - 1) {
                if (backtrack(s, i, val, count + 1)) return true;
            }
        }
        return false;
    }

    public boolean splitString(String s) {
        return backtrack(s, 0, -1, 0);
    }
}