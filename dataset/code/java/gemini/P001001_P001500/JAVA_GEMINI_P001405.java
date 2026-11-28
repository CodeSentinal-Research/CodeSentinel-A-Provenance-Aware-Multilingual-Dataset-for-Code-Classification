import java.util.HashMap;
import java.util.Map;

public class Solution {
    private int rev(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    public int countNicePairs(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        long ans = 0, MOD = 1000000007;

        for (int x : nums) {
            int diff = x - rev(x);
            int prev = map.getOrDefault(diff, 0);
            ans = (ans + prev) % MOD;
            map.put(diff, prev + 1);
        }
        return (int)ans;
    }
}