import java.util.HashMap;
import java.util.Map;

public class Solution {
    public long countBadPairs(int[] nums) {
        long n = nums.length;
        long totalPairs = n * (n - 1) / 2;
        Map<Integer, Long> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            map.put(diff, map.getOrDefault(diff, 0L) + 1);
        }

        long goodPairs = 0;
        for (long cnt : map.values()) {
            goodPairs += cnt * (cnt - 1) / 2;
        }
        return totalPairs - goodPairs;
    }
}