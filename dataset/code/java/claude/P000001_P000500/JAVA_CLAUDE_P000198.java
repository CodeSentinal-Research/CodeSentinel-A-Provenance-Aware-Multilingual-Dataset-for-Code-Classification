import java.util.*;
public class Solution {
    public boolean containsContiguous(int[] nums) {
        if (nums.length == 0) return true;
        int mn = Integer.MAX_VALUE, mx = Integer.MIN_VALUE;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            if (!s.add(x)) return false;
            mn = Math.min(mn, x); mx = Math.max(mx, x);
        }
        return mx - mn == nums.length - 1;
    }
}
