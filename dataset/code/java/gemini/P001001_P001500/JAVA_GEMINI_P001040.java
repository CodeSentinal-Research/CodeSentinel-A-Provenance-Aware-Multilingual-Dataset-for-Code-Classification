import java.util.Arrays;
import java.util.PriorityQueue;

public class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] engineers = new int[n][2];
        for (int i = 0; i < n; i++) {
            engineers[i][0] = efficiency[i];
            engineers[i][1] = speed[i];
        }
        Arrays.sort(engineers, (a, b) -> b[0] - a[0]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long speedSum = 0, best = 0;
        for (int[] eng : engineers) {
            pq.offer(eng[1]);
            speedSum += eng[1];
            if (pq.size() > k) {
                speedSum -= pq.poll();
            }
            best = Math.max(best, speedSum * eng[0]);
        }
        return (int) (best % 1000000007L);
    }
}