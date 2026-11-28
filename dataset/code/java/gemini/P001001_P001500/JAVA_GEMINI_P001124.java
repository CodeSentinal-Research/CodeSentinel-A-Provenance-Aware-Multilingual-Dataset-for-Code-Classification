import java.util.Arrays;

public class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] dist = new int[n];
        Arrays.fill(dist, 1000000000);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            int[] tmp = Arrays.copyOf(dist, n);
            for (int[] f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != 1000000000 && dist[u] + w < tmp[v]) {
                    tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }
        return dist[dst] == 1000000000 ? -1 : dist[dst];
    }
}