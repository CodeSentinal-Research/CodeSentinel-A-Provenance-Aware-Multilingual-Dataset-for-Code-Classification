public class Solution {
    public int[] rotateLeft(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) return nums;
        k %= n;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = nums[(i + k) % n];
        return res;
    }
}
