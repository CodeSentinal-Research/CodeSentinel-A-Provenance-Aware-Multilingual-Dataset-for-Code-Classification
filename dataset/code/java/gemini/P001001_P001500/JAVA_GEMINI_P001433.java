import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numIdenticalPairs(int[] nums) {
        int[] count = new int[101];
        int ans = 0;

        for (int x : nums) {
            ans += count[x]++;
        }
        return ans;
    }
}