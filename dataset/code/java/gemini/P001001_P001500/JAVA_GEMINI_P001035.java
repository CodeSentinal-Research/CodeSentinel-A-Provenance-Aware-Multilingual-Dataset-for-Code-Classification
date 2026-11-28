import java.util.PriorityQueue;

public class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{matrix[i][0], i, 0});
        }
        for (int i = 0; i < k - 1; i++) {
            int[] cur = pq.poll();
            int r = cur[1], c = cur[2];
            if (c + 1 < n) {
                pq.offer(new int[]{matrix[r][c + 1], r, c + 1});
            }
        }
        return pq.peek()[0];
    }
}