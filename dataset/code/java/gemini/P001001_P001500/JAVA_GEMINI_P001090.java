import java.util.*;

public class Solution {
    private static int[] bfs(int src, int n, List<List<Integer>> adj) {
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[src] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        int farthest = src;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.offer(v);
                    if (dist[v] > dist[farthest]) farthest = v;
                }
            }
        }
        return new int[]{farthest, dist[farthest]};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            if (n <= 1) {
                System.out.println(0);
                sc.close();
                return;
            }
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int[] first = bfs(0, n, adj);
            int[] second = bfs(first[0], n, adj);
            System.out.println(second[1]);
        }
        sc.close();
    }
}