import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int largestUniqueNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : nums) map.put(x, map.getOrDefault(x, 0) + 1);

        int maxVal = -1;
        for (int x : map.keySet()) {
            if (map.get(x) == 1) {
                maxVal = Math.max(maxVal, x);
            }
        }
        return maxVal;
    }
}