import java.util.Arrays;

public class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = capacity.length;
        int[] remaining = new int[n];
        for (int i = 0; i < n; i++) remaining[i] = capacity[i] - rocks[i];
        Arrays.sort(remaining);

        int fullBags = 0;
        for (int rem : remaining) {
            if (additionalRocks >= rem) {
                additionalRocks -= rem;
                fullBags++;
            } else {
                break;
            }
        }
        return fullBags;
    }
}