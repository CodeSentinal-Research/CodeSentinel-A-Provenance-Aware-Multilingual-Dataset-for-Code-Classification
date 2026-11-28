import java.util.*;

public class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) set.add(x);
        int k = set.size();

        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0, l = 0;

        for (int r = 0; r < nums.length; r++) {
            count.put(nums[r], count.getOrDefault(nums[r], 0) + 1);
            while (count.size() == k) {
                ans += nums.length - r;
                count.put(nums[l], count.get(nums[l]) - 1);
                if (count.get(nums[l]) == 0) count.remove(nums[l]);
                l++;
            }
        }
        return ans;
    }
}