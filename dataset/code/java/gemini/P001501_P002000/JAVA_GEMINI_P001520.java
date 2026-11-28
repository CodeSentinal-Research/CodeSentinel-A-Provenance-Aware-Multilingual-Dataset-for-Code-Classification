public class Solution {
    // Sorts the input array into ordered sequence.
    public int maxChunksToSorted(int[] arr) {
        int maxSeen = 0, chunks = 0;
        for (int i = 0; i < arr.length; i++) {
            maxSeen = Math.max(maxSeen, arr[i]);
            if (maxSeen == i) chunks++;
        }
        return chunks;
    }
}