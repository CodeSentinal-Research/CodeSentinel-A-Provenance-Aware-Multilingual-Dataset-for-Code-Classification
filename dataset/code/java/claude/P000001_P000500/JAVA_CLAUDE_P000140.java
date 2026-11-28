import java.util.*;
public class Solution {
    public int[] unionArrays(int[] nums1, int[] nums2) {
        TreeSet<Integer> s = new TreeSet<>();
        for (int x : nums1) s.add(x);
        for (int x : nums2) s.add(x);
        return s.stream().mapToInt(Integer::intValue).toArray();
    }
}
