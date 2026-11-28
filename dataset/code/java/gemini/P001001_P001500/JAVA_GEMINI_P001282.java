import java.util.*;

public class Solution {
    private int[] maxSingle(int[] nums, int k) {
        int[] stack = new int[k];
        int top = -1, drop = nums.length - k;
        for (int x : nums) {
            while (top >= 0 && stack[top] < x && drop > 0) {
                top--;
                drop--;
            }
            if (top < k - 1) {
                stack[++top] = x;
            } else {
                drop--;
            }
        }
        return stack;
    }

    private boolean greater(int[] nums1, int p1, int[] nums2, int p2) {
        while (p1 < nums1.length && p2 < nums2.length && nums1[p1] == nums2[p2]) {
            p1++;
            p2++;
        }
        return p2 == nums2.length || (p1 < nums1.length && nums1[p1] > nums2[p2]);
    }

    private int[] merge(int[] nums1, int[] nums2, int k) {
        int[] res = new int[k];
        int p1 = 0, p2 = 0;
        for (int i = 0; i < k; i++) {
            res[i] = greater(nums1, p1, nums2, p2) ? nums1[p1++] : nums2[p2++];
        }
        return res;
    }

    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] maxArr = new int[k];
        for (int i = Math.max(0, k - nums2.length); i <= Math.min(k, nums1.length); i++) {
            int[] cand = merge(maxSingle(nums1, i), maxSingle(nums2, k - i), k);
            if (greater(cand, 0, maxArr, 0)) {
                maxArr = cand;
            }
        }
        return maxArr;
    }
}