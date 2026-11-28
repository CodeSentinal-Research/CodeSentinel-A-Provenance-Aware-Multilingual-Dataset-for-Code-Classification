public class Solution {
    public int minSwaps(int[] data) {
        int totalOnes = 0;
        for (int x : data) totalOnes += x;
        if (totalOnes <= 1) return 0;

        int curOnes = 0;
        for (int i = 0; i < totalOnes; i++) curOnes += data[i];
        int maxOnes = curOnes;

        for (int i = totalOnes; i < data.length; i++) {
            curOnes += data[i] - data[i - totalOnes];
            maxOnes = Math.max(maxOnes, curOnes);
        }
        return totalOnes - maxOnes;
    }
}