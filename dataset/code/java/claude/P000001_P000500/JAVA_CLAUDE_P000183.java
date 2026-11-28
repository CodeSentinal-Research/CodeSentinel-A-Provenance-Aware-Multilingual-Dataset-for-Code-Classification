import java.util.*;
public class Solution {
    public int[] countDistinct(int[] nums, int k) {
        Map<Integer,Integer> freq = new HashMap<>();
        int n = nums.length;
        int[] res = new int[n - k + 1];
        for (int i = 0; i < n; i++) {
            freq.merge(nums[i], 1, Integer::sum);
            if (i >= k) {
                freq.merge(nums[i-k], -1, Integer::sum);
                if (freq.get(nums[i-k]) == 0) freq.remove(nums[i-k]);
            }
            if (i >= k - 1) res[i - k + 1] = freq.size();
        }
        return res;
    }
}
