import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<int[]>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt(), w = sc.nextInt();
                adj.get(u).add(new int[]{v, w});
                adj.get(v).add(new int[]{u, w});
            }
            int src = sc.nextInt();
            long[] dist = new long[n];
            Arrays.fill(dist, Long.MAX_VALUE);
            dist[src] = 0;
            PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
            pq.offer(new long[]{0, src});

            while (!pq.isEmpty()) {
                long[] cur = pq.poll();
                long d = cur[0];
                int u = (int) cur[1];
                if (d > dist[u]) continue;
                for (int[] edge : adj.get(u)) {
                    int v = edge[0], w = edge[1];
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.offer(new long[]{dist[v], v});
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print((dist[i] == Long.MAX_VALUE ? -1 : dist[i]) + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}