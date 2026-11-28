import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int countKDifference(int[] nums, int k) {
        int[] count = new int[101];
        int ans = 0;

        for (int x : nums) {
            if (x - k >= 1) ans += count[x - k];
            if (x + k <= 100) ans += count[x + k];
            count[x]++;
        }
        return ans;
    }
}