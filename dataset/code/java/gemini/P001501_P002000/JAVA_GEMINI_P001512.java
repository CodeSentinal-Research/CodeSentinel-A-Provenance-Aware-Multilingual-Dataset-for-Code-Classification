import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int curSum = 0, ans = 0;

        for (int x : nums) {
            curSum += x;
            ans += count.getOrDefault(curSum - goal, 0);
            count.put(curSum, count.getOrDefault(curSum, 0) + 1);
        }
        return ans;
    }
}