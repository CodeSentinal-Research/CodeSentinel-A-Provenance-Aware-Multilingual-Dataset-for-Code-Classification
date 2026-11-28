import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int countPairs(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for (int x : nums) {
            count += map.getOrDefault(target - x, 0);
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        return count;
    }
}