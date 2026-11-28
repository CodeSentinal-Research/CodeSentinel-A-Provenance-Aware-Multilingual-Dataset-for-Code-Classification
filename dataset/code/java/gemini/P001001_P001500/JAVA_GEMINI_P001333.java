import java.util.*;

public class Solution {
    private void backtrack(String num, int target, int idx, String path, long eval, long mult, List<String> res) {
        if (idx == num.length()) {
            if (eval == target) res.add(path);
            return;
        }

        for (int i = idx + 1; i <= num.length(); i++) {
            String part = num.substring(idx, i);
            if (part.charAt(0) == '0' && part.length() > 1) break;
            long val = Long.parseLong(part);

            if (idx == 0) {
                backtrack(num, target, i, part, val, val, res);
            } else {
                backtrack(num, target, i, path + "+" + part, eval + val, val, res);
                backtrack(num, target, i, path + "-" + part, eval - val, -val, res);
                backtrack(num, target, i, path + "*" + part, eval - mult + mult * val, mult * val, res);
            }
        }
    }

    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<>();
        backtrack(num, target, 0, "", 0, 0, res);
        return res;
    }
}