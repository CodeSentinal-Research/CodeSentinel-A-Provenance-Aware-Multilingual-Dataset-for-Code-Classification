import java.util.*;

public class Solution {
    public int[] union(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums1) set.add(x);
        for (int x : nums2) set.add(x);
        int[] res = new int[set.size()];
        int idx = 0;
        for (int x : set) res[idx++] = x;
        return res;
    }
}