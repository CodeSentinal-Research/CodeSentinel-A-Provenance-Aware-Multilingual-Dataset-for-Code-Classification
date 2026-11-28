import java.util.*;
public class Solution {
    public int[] findPair(int[] nums, int target) {
        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            if (seen.contains(target - x)) return new int[]{target - x, x};
            seen.add(x);
        }
        return new int[]{};
    }
}
