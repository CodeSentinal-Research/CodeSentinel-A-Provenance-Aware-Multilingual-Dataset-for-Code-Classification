import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) set.add(x);

        int maxK = -1;
        for (int x : nums) {
            if (x > 0 && set.contains(-x)) {
                maxK = Math.max(maxK, x);
            }
        }
        return maxK;
    }
}