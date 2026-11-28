import java.util.Arrays;
public class Solution {
    public int[] findTriplet(int[] nums, int target) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int l = i+1, r = nums.length-1;
            while (l < r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s == target) return new int[]{nums[i],nums[l],nums[r]};
                else if (s < target) l++;
                else r--;
            }
        }
        return new int[]{};
    }
}
