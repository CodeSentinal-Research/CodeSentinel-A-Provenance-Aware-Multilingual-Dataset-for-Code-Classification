import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int[] count = new int[nums.length + 1];
        count[0] = 1;
        int curOdds = 0, ans = 0;

        for (int x : nums) {
            curOdds += (x % 2 != 0 ? 1 : 0);
            if (curOdds >= k) ans += count[curOdds - k];
            count[curOdds]++;
        }
        return ans;
    }
}