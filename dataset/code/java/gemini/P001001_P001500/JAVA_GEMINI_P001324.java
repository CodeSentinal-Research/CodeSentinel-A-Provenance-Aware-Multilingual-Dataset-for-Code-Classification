import java.util.*;

public class Solution {
    private void backtrack(int start, int k, int n, List<Integer> cur, List<List<Integer>> res) {
        if (cur.size() == k) {
            if (n == 0) res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > n) break;
            cur.add(i);
            backtrack(i + 1, k, n - i, cur, res);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(1, k, n, new ArrayList<>(), res);
        return res;
    }
}