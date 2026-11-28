import java.util.*;

public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for (int x : nums1) set1.add(x);
        Set<Integer> inter = new HashSet<>();
        for (int x : nums2) {
            if (set1.contains(x)) inter.add(x);
        }
        int[] res = new int[inter.size()];
        int idx = 0;
        for (int x : inter) res[idx++] = x;
        return res;
    }
}