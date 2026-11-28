import java.util.*;

public class Solution {
    public String[] findWords(String[] words) {
        int[] rowMap = new int[26];
        String[] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (int r = 0; r < 3; r++) {
            for (char c : rows[r].toCharArray()) rowMap[c - 'a'] = r;
        }

        List<String> res = new ArrayList<>();
        for (String w : words) {
            String lower = w.toLowerCase();
            int r = rowMap[lower.charAt(0) - 'a'];
            boolean valid = true;
            for (char c : lower.toCharArray()) {
                if (rowMap[c - 'a'] != r) {
                    valid = false;
                    break;
                }
            }
            if (valid) res.add(w);
        }
        return res.toArray(new String[0]);
    }
}