import java.util.*;
public class Solution {
    public int countPairsWithSum(int[] nums, int target) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        int count = 0;
        Set<Integer> visited = new HashSet<>();
        for (int x : cnt.keySet()) {
            int y = target - x;
            if (cnt.containsKey(y) && !visited.contains(y)) {
                if (x == y) count += (long)cnt.get(x)*(cnt.get(x)-1)/2;
                else count += (long)cnt.get(x)*cnt.get(y);
                visited.add(x);
            }
        }
        return count;
    }
}
