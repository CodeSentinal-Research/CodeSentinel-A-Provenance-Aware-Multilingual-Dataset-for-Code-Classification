import java.util.*;

public class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int day = 0, count = 0, i = 0, n = events.length;

        while (i < n || !pq.isEmpty()) {
            if (pq.isEmpty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                pq.offer(events[i++][1]);
            }
            pq.poll();
            count++;
            day++;
            while (!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }
        }
        return count;
    }
}