import java.util.*;

public class Solution {
    static class Range {
        long low, high;
        Range(long l, long h) { low = l; high = h; }
    }

    public boolean canRepresentBSTLevelOrder(int[] levelOrder) {
        if (levelOrder.length == 0) return true;
        Queue<Range> q = new LinkedList<>();
        q.offer(new Range(Long.MIN_VALUE, Long.MAX_VALUE));
        int idx = 0;

        while (!q.isEmpty() && idx < levelOrder.length) {
            Range r = q.poll();
            int val = levelOrder[idx];
            if (val > r.low && val < r.high) {
                idx++;
                q.offer(new Range(r.low, val));
                q.offer(new Range(val, r.high));
            }
        }
        return idx == levelOrder.length;
    }
}