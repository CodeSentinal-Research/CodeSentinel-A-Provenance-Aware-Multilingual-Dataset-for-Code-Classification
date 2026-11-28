import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<int[]>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            int[] inDeg = new int[n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt(), w = sc.nextInt();
                adj.get(u).add(new int[]{v, w});
                inDeg[v]++;
            }
            int src = sc.nextInt();
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (inDeg[i] == 0) q.offer(i);
            }
            List<Integer> order = new ArrayList<>();
            while (!q.isEmpty()) {
                int u = q.poll();
                order.add(u);
                for (int[] edge : adj.get(u)) {
                    if (--inDeg[edge[0]] == 0) q.offer(edge[0]);
                }
            }
            long[] dist = new long[n];
            Arrays.fill(dist, Long.MAX_VALUE);
            dist[src] = 0;
            for (int u : order) {
                if (dist[u] != Long.MAX_VALUE) {
                    for (int[] edge : adj.get(u)) {
                        int v = edge[0], w = edge[1];
                        if (dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                        }
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