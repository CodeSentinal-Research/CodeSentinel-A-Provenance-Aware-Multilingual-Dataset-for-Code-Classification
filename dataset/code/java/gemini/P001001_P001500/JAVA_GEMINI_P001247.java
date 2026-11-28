import java.util.*;

public class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Arrays.sort(nums1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < n; i++) pq.offer(new int[]{nums2[i], i});

        int l = 0, r = n - 1;
        int[] res = new int[n];

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int val = cur[0], idx = cur[1];
            if (nums1[r] > val) {
                res[idx] = nums1[r--];
            } else {
                res[idx] = nums1[l++];
            }
        }
        return res;
    }
}