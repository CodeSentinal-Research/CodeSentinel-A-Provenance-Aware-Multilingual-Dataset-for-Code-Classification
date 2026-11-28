public class Solution {
    public int[] findMissingRepeating(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        int rep = -1, miss = -1;
        for (int x : nums) { cnt[x]++; if (cnt[x] == 2) rep = x; }
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) { miss = i; break; }
        return new int[]{rep, miss};
    }
}
