import java.util.*;

public class Solution {
    public int[][] allPairs(int target, int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for (int x : nums1) set1.add(x);

        Arrays.sort(nums2);
        List<int[]> list = new ArrayList<>();
        for (int y : nums2) {
            int x = target - y;
            if (set1.contains(x)) {
                list.add(new int[]{x, y});
            }
        }
        list.sort((a, b) -> a[0] - b[0]);
        return list.toArray(new int[list.size()][]);
    }
}