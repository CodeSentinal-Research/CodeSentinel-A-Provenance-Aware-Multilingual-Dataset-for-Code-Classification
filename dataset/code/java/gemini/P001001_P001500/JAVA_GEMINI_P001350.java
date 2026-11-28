import java.util.*;

public class Solution {
    private List<String> res = new ArrayList<>();

    private void backtrack(int n, StringBuilder sb) {
        if (sb.length() == n) {
            res.add(sb.toString());
            return;
        }
        for (char c : new char[]{'a', 'b', 'c'}) {
            if (sb.length() == 0 || sb.charAt(sb.length() - 1) != c) {
                sb.append(c);
                backtrack(n, sb);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }

    public String getHappyString(int n, int k) {
        backtrack(n, new StringBuilder());
        return k <= res.size() ? res.get(k - 1) : "";
    }
}