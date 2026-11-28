public class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] allow = new boolean[26];
        for (char c : allowed.toCharArray()) allow[c - 'a'] = true;

        int count = 0;
        for (String w : words) {
            boolean consistent = true;
            for (char c : w.toCharArray()) {
                if (!allow[c - 'a']) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
}