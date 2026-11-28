import java.util.*;

public class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[][] arrPos = new int[n][2];
        for (int i = 0; i < n; i++) {
            arrPos[i][0] = i;
            arrPos[i][1] = nums[i];
        }
        Arrays.sort(arrPos, (a, b) -> a[1] - b[1]);

        boolean[] visited = new boolean[n];
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arrPos[i][0] == i) continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j][0];
                cycleSize++;
            }

            if (cycleSize > 0) swaps += cycleSize - 1;
        }
        return swaps;
    }
}