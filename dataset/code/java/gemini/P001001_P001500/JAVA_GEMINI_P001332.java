import java.util.*;

public class Solution {
    private Set<String> res = new HashSet<>();

    private void backtrack(String s, int idx, int open, int close, int lRem, int rRem, StringBuilder sb) {
        if (idx == s.length()) {
            if (lRem == 0 && rRem == 0) res.add(sb.toString());
            return;
        }

        char c = s.charAt(idx);
        if (c == '(' && lRem > 0) {
            backtrack(s, idx + 1, open, close, lRem - 1, rRem, sb);
        } else if (c == ')' && rRem > 0) {
            backtrack(s, idx + 1, open, close, lRem, rRem - 1, sb);
        }

        sb.append(c);
        if (c != '(' && c != ')') {
            backtrack(s, idx + 1, open, close, lRem, rRem, sb);
        } else if (c == '(') {
            backtrack(s, idx + 1, open + 1, close, lRem, rRem, sb);
        } else if (close < open) {
            backtrack(s, idx + 1, open, close + 1, lRem, rRem, sb);
        }
        sb.deleteCharAt(sb.length() - 1);
    }

    public List<String> removeInvalidParentheses(String s) {
        int lRem = 0, rRem = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') lRem++;
            else if (c == ')') {
                if (lRem > 0) lRem--;
                else rRem++;
            }
        }
        backtrack(s, 0, 0, 0, lRem, rRem, new StringBuilder());
        return new ArrayList<>(res);
    }
}