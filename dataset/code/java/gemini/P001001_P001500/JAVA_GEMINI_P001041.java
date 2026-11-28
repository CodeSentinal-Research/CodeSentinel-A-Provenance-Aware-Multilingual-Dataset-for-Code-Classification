import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i][0] = (double) wage[i] / quality[i];
            workers[i][1] = quality[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        double qSum = 0, ans = Double.MAX_VALUE;
        for (double[] w : workers) {
            pq.offer((int) w[1]);
            qSum += w[1];
            if (pq.size() > k) {
                qSum -= pq.poll();
            }
            if (pq.size() == k) {
                ans = Math.min(ans, qSum * w[0]);
            }
        }
        return ans;
    }
}