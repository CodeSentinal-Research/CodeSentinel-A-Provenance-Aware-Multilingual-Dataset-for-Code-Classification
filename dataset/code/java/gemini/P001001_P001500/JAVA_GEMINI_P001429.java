import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                map.put(prod, map.getOrDefault(prod, 0) + 1);
            }
        }

        int ans = 0;
        for (int cnt : map.values()) {
            ans += 8 * cnt * (cnt - 1) / 2;
        }
        return ans;
    }
}