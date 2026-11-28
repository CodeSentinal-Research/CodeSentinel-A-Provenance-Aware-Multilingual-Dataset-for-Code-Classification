import java.util.List;

public class Solution {
    private boolean isSubseq(String s, String w) {
        int i = 0, j = 0;
        while (i < s.length() && j < w.length()) {
            if (s.charAt(i) == w.charAt(j)) j++;
            i++;
        }
        return j == w.length();
    }

    public String findLongestWord(String s, List<String> dictionary) {
        String best = "";
        for (String w : dictionary) {
            if (isSubseq(s, w)) {
                if (w.length() > best.length() || (w.length() == best.length() && w.compareTo(best) < 0)) {
                    best = w;
                }
            }
        }
        return best;
    }
}