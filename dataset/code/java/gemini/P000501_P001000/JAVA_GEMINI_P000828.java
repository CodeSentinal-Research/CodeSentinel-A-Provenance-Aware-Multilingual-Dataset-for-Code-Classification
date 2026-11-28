import java.util.Arrays;
import java.util.TreeMap;

public class Solution {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < intervals.length; i++) {
            map.put(intervals[i][0], i);
        }
        int[] res = new int[intervals.length];
        for (int i = 0; i < intervals.length; i++) {
            Integer rightStart = map.ceilingKey(intervals[i][1]);
            res[i] = (rightStart == null) ? -1 : map.get(rightStart);
        }
        return res;
    }
}