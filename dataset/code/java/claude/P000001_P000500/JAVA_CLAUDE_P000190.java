// P000190: Find Duplicate in Array of N+1 Elements
// Approach: index-marking (negate value at visited index)
// Different from P000137 which uses Floyd's cycle detection
public class Solution {
    public int findDuplicateInNPlusOne(int[] nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]);
            if (nums[idx] < 0) {
                duplicate = idx;
                break;
            }
            nums[idx] = -nums[idx];
        }
        // restore array
        for (int i = 0; i < nums.length; i++)
            if (nums[i] < 0) nums[i] = -nums[i];
        return duplicate;
    }
}
