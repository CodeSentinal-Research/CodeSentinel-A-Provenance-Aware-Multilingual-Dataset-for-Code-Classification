import java.util.Arrays;
public class Solution {
    public int[] rearrangeAlternately(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] res = new int[n];
        int l = 0, r = n - 1, idx = 0;
        boolean toggle = true;
        while (l <= r) {
            if (toggle) res[idx++] = nums[r--];
            else res[idx++] = nums[l++];
            toggle = !toggle;
        }
        return res;
    }
}
