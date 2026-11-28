import java.util.*;

public class Solution {
    private String getNorm(String s) {
        Map<Character, Integer> seen = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            seen.putIfAbsent(c, seen.size());
            sb.append(seen.get(c)).append(",");
        }
        return sb.toString();
    }

    public List<String> findAndReplacePattern(String[] words, String pattern) {
        String patNorm = getNorm(pattern);
        List<String> res = new ArrayList<>();
        for (String w : words) {
            if (getNorm(w).equals(patNorm)) res.add(w);
        }
        return res;
    }
}