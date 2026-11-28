import java.util.*;

public class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] engineers = new int[n][2];
        for (int i = 0; i < n; i++) {
            engineers[i][0] = efficiency[i];
            engineers[i][1] = speed[i];
        }
        Arrays.sort(engineers, (a, b) -> b[0] - a[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long speedSum = 0, maxPerf = 0;
        long MOD = 1000000007;

        for (int[] eng : engineers) {
            int eff = eng[0], spd = eng[1];
            pq.offer(spd);
            speedSum += spd;
            if (pq.size() > k) {
                speedSum -= pq.poll();
            }
            maxPerf = Math.max(maxPerf, speedSum * eff);
        }
        return (int)(maxPerf % MOD);
    }
}