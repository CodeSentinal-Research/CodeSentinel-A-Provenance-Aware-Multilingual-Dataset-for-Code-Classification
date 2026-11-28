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
            boolean[] vis = new boolean[n];
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
            pq.offer(new int[]{0, 0});
            long total = 0;

            while (!pq.isEmpty()) {
                int[] cur = pq.poll();
                int w = cur[0], u = cur[1];
                if (vis[u]) continue;
                vis[u] = true;
                total += w;
                for (int[] edge : adj.get(u)) {
                    if (!vis[edge[0]]) {
                        pq.offer(new int[]{edge[1], edge[0]});
                    }
                }
            }
            System.out.println(total);
        }
        sc.close();
    }
}