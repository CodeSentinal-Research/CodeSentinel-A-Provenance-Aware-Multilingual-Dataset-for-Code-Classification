import java.util.*;
public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>(), res = new HashSet<>();
        for (int x : nums1) s1.add(x);
        for (int x : nums2) if (s1.contains(x)) res.add(x);
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
