import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int mostFrequent(int[] nums, int key) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxCount = 0, bestTarget = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];
                int cnt = map.getOrDefault(target, 0) + 1;
                map.put(target, cnt);
                if (cnt > maxCount) {
                    maxCount = cnt;
                    bestTarget = target;
                }
            }
        }
        return bestTarget;
    }
}