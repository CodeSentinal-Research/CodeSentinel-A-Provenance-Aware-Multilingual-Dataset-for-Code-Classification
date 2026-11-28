import java.util.*;

public class Solution {
    public int activitySelection(int[] start, int[] end, int n) {
        int[][] act = new int[n][2];
        for (int i = 0; i < n; i++) {
            act[i][0] = start[i];
            act[i][1] = end[i];
        }
        Arrays.sort(act, (a, b) -> a[1] - b[1]);

        int count = 0, lastEnd = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (act[i][0] > lastEnd) {
                count++;
                lastEnd = act[i][1];
            }
        }
        return count;
    }
}