import java.util.*;
public class Solution {
    public List<Integer> findAllDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int x : nums) {
            int idx = Math.abs(x) - 1;
            if (nums[idx] < 0) res.add(Math.abs(x));
            else nums[idx] = -nums[idx];
        }
        return res;
    }
}
