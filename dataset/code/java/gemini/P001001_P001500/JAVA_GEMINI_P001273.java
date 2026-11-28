import java.util.*;

public class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int b : barcodes) count.put(b, count.getOrDefault(b, 0) + 1);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int k : count.keySet()) pq.offer(new int[]{k, count.get(k)});

        int[] res = new int[barcodes.length];
        int idx = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int val = cur[0], cnt = cur[1];
            while (cnt-- > 0) {
                res[idx] = val;
                idx += 2;
                if (idx >= barcodes.length) idx = 1;
            }
        }
        return res;
    }
}