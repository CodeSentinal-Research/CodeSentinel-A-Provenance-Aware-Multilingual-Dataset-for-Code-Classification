import java.util.*;

public class Solution {
    private void backtrack(int first, int[] nums, List<List<Integer>> res) {
        if (first == nums.length) {
            List<Integer> list = new ArrayList<>();
            for (int n : nums) list.add(n);
            res.add(list);
            return;
        }
        for (int i = first; i < nums.length; i++) {
            int tmp = nums[first]; nums[first] = nums[i]; nums[i] = tmp;
            backtrack(first + 1, nums, res);
            tmp = nums[first]; nums[first] = nums[i]; nums[i] = tmp;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, nums, res);
        return res;
    }
}