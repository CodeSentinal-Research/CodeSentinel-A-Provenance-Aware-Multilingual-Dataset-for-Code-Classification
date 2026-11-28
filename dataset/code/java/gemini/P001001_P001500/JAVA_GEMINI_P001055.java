import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int stops = 0, curFuel = startFuel, i = 0, n = stations.length;
        while (curFuel < target) {
            while (i < n && stations[i][0] <= curFuel) {
                pq.offer(stations[i][1]);
                i++;
            }
            if (pq.isEmpty()) return -1;
            curFuel += pq.poll();
            stops++;
        }
        return stops;
    }
}