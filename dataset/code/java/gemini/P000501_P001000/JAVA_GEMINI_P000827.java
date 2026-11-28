import java.util.Arrays;

public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int maxR = 0;
        for (int h : houses) {
            int idx = Arrays.binarySearch(heaters, h);
            if (idx < 0) {
                idx = -(idx + 1);
            }
            int dist1 = (idx < heaters.length) ? heaters[idx] - h : Integer.MAX_VALUE;
            int dist2 = (idx > 0) ? h - heaters[idx - 1] : Integer.MAX_VALUE;
            maxR = Math.max(maxR, Math.min(dist1, dist2));
        }
        return maxR;
    }
}