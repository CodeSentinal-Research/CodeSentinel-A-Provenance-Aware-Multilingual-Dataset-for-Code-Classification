import java.util.*;

public class Solution {
    private void backtrack(int[] nums, int idx, List<Integer> cur, List<List<Integer>> res) {
        if (idx == nums.length) {
            res.add(new ArrayList<>(cur));
            return;
        }
        cur.add(nums[idx]);
        backtrack(nums, idx + 1, cur, res);
        cur.remove(cur.size() - 1);

        backtrack(nums, idx + 1, cur, res);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, 0, new ArrayList<>(), res);
        return res;
    }
}