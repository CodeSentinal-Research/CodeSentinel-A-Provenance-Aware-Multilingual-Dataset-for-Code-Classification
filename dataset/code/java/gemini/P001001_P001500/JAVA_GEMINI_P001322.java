import java.util.*;

public class Solution {
    private void backtrack(int[] candidates, int target, int idx, List<Integer> cur, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }
        if (target < 0 || idx == candidates.length) return;

        cur.add(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, cur, res);
        cur.remove(cur.size() - 1);

        backtrack(candidates, target, idx + 1, cur, res);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }
}