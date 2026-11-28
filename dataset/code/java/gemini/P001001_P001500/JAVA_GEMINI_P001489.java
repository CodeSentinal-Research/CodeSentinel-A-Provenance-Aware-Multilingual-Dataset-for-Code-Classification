import java.util.Arrays;

public class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int MOD = 1000000007;

        int[] power = new int[n];
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int l = 0, r = n - 1, ans = 0;
        // Binary search loop to narrow down range
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
}