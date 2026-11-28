import java.util.*;

public class Solution {
    private void backtrack(String s, int idx, int dots, StringBuilder sb, List<String> res) {
        if (dots == 4 && idx == s.length()) {
            res.add(sb.substring(0, sb.length() - 1));
            return;
        }
        if (dots > 4) return;

        for (int l = 1; l <= 3; l++) {
            if (idx + l <= s.length()) {
                String part = s.substring(idx, idx + l);
                if ((part.charAt(0) != '0' || l == 1) && Integer.parseInt(part) <= 255) {
                    int len = sb.length();
                    sb.append(part).append(".");
                    backtrack(s, idx + l, dots + 1, sb, res);
                    sb.setLength(len);
                }
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        backtrack(s, 0, 0, new StringBuilder(), res);
        return res;
    }
}