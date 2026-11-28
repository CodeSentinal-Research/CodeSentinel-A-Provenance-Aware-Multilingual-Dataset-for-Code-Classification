import java.util.*;

public class Solution {
    public int[] recoverArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length / 2;

        for (int i = 1; i < nums.length; i++) {
            int diff = nums[i] - nums[0];
            if (diff <= 0 || diff % 2 != 0) continue;
            int k = diff / 2;

            Map<Integer, Integer> map = new HashMap<>();
            for (int x : nums) map.put(x, map.getOrDefault(x, 0) + 1);

            int[] res = new int[n];
            int idx = 0;

            for (int x : nums) {
                if (map.get(x) == 0) continue;
                if (map.getOrDefault(x + 2 * k, 0) == 0) break;

                res[idx++] = x + k;
                map.put(x, map.get(x) - 1);
                map.put(x + 2 * k, map.get(x + 2 * k) - 1);
            }

            if (idx == n) return res;
        }
        return new int[0];
    }
}