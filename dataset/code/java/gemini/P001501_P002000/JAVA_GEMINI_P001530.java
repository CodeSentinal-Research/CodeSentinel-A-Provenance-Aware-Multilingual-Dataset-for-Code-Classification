import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        int l = 0, curSum = 0, maxSum = 0;

        for (int num : nums) {
            while (seen.contains(num)) {
                seen.remove(nums[l]);
                curSum -= nums[l++];
            }
            seen.add(num);
            curSum += num;
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }
}