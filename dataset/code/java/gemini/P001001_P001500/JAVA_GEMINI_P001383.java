import java.util.*;

public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums1) count.put(n, count.getOrDefault(n, 0) + 1);

        List<Integer> list = new ArrayList<>();
        for (int n : nums2) {
            if (count.getOrDefault(n, 0) > 0) {
                list.add(n);
                count.put(n, count.get(n) - 1);
            }
        }

        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) res[i] = list.get(i);
        return res;
    }
}