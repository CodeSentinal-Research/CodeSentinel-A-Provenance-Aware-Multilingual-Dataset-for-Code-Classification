import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : arr) map.put(x, map.getOrDefault(x, 0) + 1);

        int maxLucky = -1;
        for (int k : map.keySet()) {
            if (k == map.get(k)) {
                maxLucky = Math.max(maxLucky, k);
            }
        }
        return maxLucky;
    }
}