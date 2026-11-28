import java.util.*;

public class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : nums) map.put(x, map.getOrDefault(x, 0) + 1);

        int ans = 0;
        if (k == 0) {
            for (int cnt : map.values()) {
                if (cnt > 1) ans++;
            }
        } else {
            for (int x : map.keySet()) {
                if (map.containsKey(x + k)) ans++;
            }
        }
        return ans;
    }
}