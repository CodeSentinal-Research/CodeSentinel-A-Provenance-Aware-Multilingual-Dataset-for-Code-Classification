import java.util.*;

public class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxGaps = 0;

        for (List<Integer> row : wall) {
            int edge = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                edge += row.get(i);
                int count = map.getOrDefault(edge, 0) + 1;
                map.put(edge, count);
                maxGaps = Math.max(maxGaps, count);
            }
        }
        return wall.size() - maxGaps;
    }
}