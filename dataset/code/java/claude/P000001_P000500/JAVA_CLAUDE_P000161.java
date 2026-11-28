import java.util.*;
public class Solution {
    public List<int[]> findAllPairs(int[] nums, int target) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        List<int[]> res = new ArrayList<>();
        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            int y = target - x;
            if (cnt.containsKey(y) && !seen.contains(Math.min(x,y))) {
                if (x != y || cnt.get(x) >= 2) res.add(new int[]{Math.min(x,y), Math.max(x,y)});
                seen.add(Math.min(x,y));
            }
        }
        return res;
    }
}
