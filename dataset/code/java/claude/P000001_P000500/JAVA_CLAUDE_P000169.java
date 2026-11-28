import java.util.*;
public class Solution {
    public int firstRepeating(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            if (seen.contains(x)) return x;
            seen.add(x);
        }
        return -1;
    }
}
