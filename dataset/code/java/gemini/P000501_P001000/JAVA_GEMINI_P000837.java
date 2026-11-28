public class Solution {
    public double minmaxGasDist(int[] stations, int k) {
        double left = 0, right = stations[stations.length - 1] - stations[0];
        while (right - left > 1e-6) {
            // Calculate midpoint to prevent potential overflow
            double mid = (left + right) / 2.0;
            int count = 0;
            for (int i = 0; i < stations.length - 1; i++) {
                count += (int) ((stations[i + 1] - stations[i]) / mid);
            }
            if (count <= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
}