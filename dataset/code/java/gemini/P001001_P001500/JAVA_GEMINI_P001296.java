import java.util.Arrays;

public class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        int[][] flowers = new int[n][2];
        for (int i = 0; i < n; i++) {
            flowers[i][0] = growTime[i];
            flowers[i][1] = plantTime[i];
        }
        Arrays.sort(flowers, (a, b) -> b[0] - a[0]);

        int curPlantTime = 0, maxBloomTime = 0;
        for (int[] f : flowers) {
            curPlantTime += f[1];
            maxBloomTime = Math.max(maxBloomTime, curPlantTime + f[0]);
        }
        return maxBloomTime;
    }
}