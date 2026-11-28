import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int findMaximumXOR(int[] nums) {
        int maxXor = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            Set<Integer> prefixes = new HashSet<>();
            for (int num : nums) {
                prefixes.add(num & mask);
            }
            int greedyTarget = maxXor | (1 << i);
            for (int p : prefixes) {
                if (prefixes.contains(p ^ greedyTarget)) {
                    maxXor = greedyTarget;
                    break;
                }
            }
        }
        return maxXor;
    }
}