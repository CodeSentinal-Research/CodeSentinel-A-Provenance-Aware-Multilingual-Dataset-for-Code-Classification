import java.util.*;

public class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        long cur = startFuel;
        int stops = 0, i = 0, n = stations.length;

        while (cur < target) {
            while (i < n && stations[i][0] <= cur) {
                pq.offer(stations[i++][1]);
            }
            if (pq.isEmpty()) return -1;
            cur += pq.poll();
            stops++;
        }
        return stops;
    }
}