import java.util.*;

public class Solution {
    private void backtrack(int n, StringBuilder sb, List<String> res) {
        if (sb.length() == n) {
            res.add(sb.toString());
            return;
        }
        sb.append('1');
        backtrack(n, sb, res);
        sb.deleteCharAt(sb.length() - 1);

        if (sb.length() == 0 || sb.charAt(sb.length() - 1) != '0') {
            sb.append('0');
            backtrack(n, sb, res);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public List<String> validStrings(int n) {
        List<String> res = new ArrayList<>();
        backtrack(n, new StringBuilder(), res);
        return res;
    }
}