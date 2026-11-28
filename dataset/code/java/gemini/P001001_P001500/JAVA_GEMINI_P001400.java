import java.util.*;

public class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>();
        for (int n : nums1) s1.add(n);
        Set<Integer> s2 = new HashSet<>();
        for (int n : nums2) s2.add(n);

        List<Integer> diff1 = new ArrayList<>();
        for (int n : s1) if (!s2.contains(n)) diff1.add(n);

        List<Integer> diff2 = new ArrayList<>();
        for (int n : s2) if (!s1.contains(n)) diff2.add(n);

        return Arrays.asList(diff1, diff2);
    }
}