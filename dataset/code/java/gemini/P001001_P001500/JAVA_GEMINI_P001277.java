public class Solution {
    // Sorts the input array into ordered sequence.
    public int maxChunksToSorted(int[] arr) {
        int curMax = 0, chunks = 0;
        for (int i = 0; i < arr.length; i++) {
            curMax = Math.max(curMax, arr[i]);
            if (curMax == i) chunks++;
        }
        return chunks;
    }
}