import java.util.*;

public class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) return false;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int x : nums) map.put(x, map.getOrDefault(x, 0) + 1);

        for (int x : map.keySet()) {
            int freq = map.get(x);
            if (freq > 0) {
                for (int i = 0; i < k; i++) {
                    if (map.getOrDefault(x + i, 0) < freq) return false;
                    map.put(x + i, map.get(x + i) - freq);
                }
            }
        }
        return true;
    }
}