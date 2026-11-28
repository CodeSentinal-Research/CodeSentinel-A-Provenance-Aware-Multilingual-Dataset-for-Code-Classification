import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int curSum = 0, ans = 0;

        for (int x : nums) {
            curSum += x;
            ans += count.getOrDefault(curSum - k, 0);
            count.put(curSum, count.getOrDefault(curSum, 0) + 1);
        }
        return ans;
    }
}