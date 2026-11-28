import java.util.*;

public class Solution {
    private boolean backtrack(String num, int idx, List<Integer> res) {
        if (idx == num.length() && res.size() >= 3) return true;
        for (int i = idx + 1; i <= num.length(); i++) {
            if (num.charAt(idx) == '0' && i > idx + 1) break;
            long val = Long.parseLong(num.substring(idx, i));
            if (val > Integer.MAX_VALUE) break;

            int size = res.size();
            if (size >= 2) {
                long sum = (long) res.get(size - 1) + res.get(size - 2);
                if (val < sum) continue;
                else if (val > sum) break;
            }

            res.add((int) val);
            if (backtrack(num, i, res)) return true;
            res.remove(res.size() - 1);
        }
        return false;
    }

    public List<Integer> splitIntoFibonacci(String num) {
        List<Integer> res = new ArrayList<>();
        backtrack(num, 0, res);
        return res;
    }
}