import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int a : answers) map.put(a, map.getOrDefault(a, 0) + 1);

        int ans = 0;
        for (int x : map.keySet()) {
            int cnt = map.get(x);
            int groupSize = x + 1;
            int numGroups = (cnt + groupSize - 1) / groupSize;
            ans += numGroups * groupSize;
        }
        return ans;
    }
}