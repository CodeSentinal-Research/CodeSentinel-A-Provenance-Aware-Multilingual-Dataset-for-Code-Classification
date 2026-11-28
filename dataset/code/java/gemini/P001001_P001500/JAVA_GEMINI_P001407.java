import java.util.*;

public class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 != 0) return new int[0];
        Arrays.sort(changed);

        Map<Integer, Integer> map = new HashMap<>();
        for (int x : changed) map.put(x, map.getOrDefault(x, 0) + 1);

        int[] res = new int[changed.length / 2];
        int idx = 0;

        for (int x : changed) {
            if (map.get(x) == 0) continue;
            if (map.getOrDefault(2 * x, 0) == 0) return new int[0];

            res[idx++] = x;
            map.put(x, map.get(x) - 1);
            map.put(2 * x, map.get(2 * x) - 1);
        }
        return res;
    }
}