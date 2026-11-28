import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] p1 : points) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int[] p2 : points) {
                int dx = p1[0] - p2[0];
                int dy = p1[1] - p2[1];
                int d = dx * dx + dy * dy;
                map.put(d, map.getOrDefault(d, 0) + 1);
            }
            for (int val : map.values()) {
                ans += val * (val - 1);
            }
        }
        return ans;
    }
}