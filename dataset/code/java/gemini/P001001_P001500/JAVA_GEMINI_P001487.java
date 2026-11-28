import java.util.*;

public class Solution {
    private boolean match(String q, String pattern) {
        int j = 0;
        for (char c : q.toCharArray()) {
            if (j < pattern.length() && c == pattern.charAt(j)) {
                j++;
            } else if (Character.isUpperCase(c)) {
                return false;
            }
        }
        return j == pattern.length();
    }

    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res = new ArrayList<>();
        for (String q : queries) {
            res.add(match(q, pattern));
        }
        return res;
    }
}