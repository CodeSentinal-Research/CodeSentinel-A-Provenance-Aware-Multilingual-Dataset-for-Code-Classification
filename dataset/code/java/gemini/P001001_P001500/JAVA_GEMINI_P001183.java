import java.util.*;

public class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> dp = new HashMap<>();
        for (int s : stones) dp.put(s, new HashSet<>());
        dp.get(0).add(0);

        for (int s : stones) {
            for (int k : dp.get(s)) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && dp.containsKey(s + step)) {
                        dp.get(s + step).add(step);
                    }
                }
            }
        }
        return !dp.get(stones[stones.length - 1]).isEmpty();
    }
}