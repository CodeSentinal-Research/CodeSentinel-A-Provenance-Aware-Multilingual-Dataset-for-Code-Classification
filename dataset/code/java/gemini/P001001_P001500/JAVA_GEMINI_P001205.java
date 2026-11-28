public class Solution {
    public int findNumberOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] lengths = new int[n];
        int[] counts = new int[n];
        for (int i = 0; i < n; i++) { lengths[i] = 1; counts[i] = 1; }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lengths[j] + 1 > lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[j] + 1 == lengths[i]) {
                        counts[i] += counts[j];
                    }
                }
            }
        }

        int maxLen = 0;
        for (int l : lengths) maxLen = Math.max(maxLen, l);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (lengths[i] == maxLen) ans += counts[i];
        }
        return ans;
    }
}