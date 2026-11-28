import java.util.*;

public class Solution {
    private void backtrack(String word, int idx, StringBuilder sb, int count, List<String> res) {
        int len = sb.length();
        if (idx == word.length()) {
            if (count > 0) sb.append(count);
            res.add(sb.toString());
            sb.setLength(len);
            return;
        }

        // Abbreviate
        backtrack(word, idx + 1, sb, count + 1, res);

        // Keep
        if (count > 0) sb.append(count);
        sb.append(word.charAt(idx));
        backtrack(word, idx + 1, sb, 0, res);
        sb.setLength(len);
    }

    public List<String> generateAbbreviations(String word) {
        List<String> res = new ArrayList<>();
        backtrack(word, 0, new StringBuilder(), 0, res);
        return res;
    }
}