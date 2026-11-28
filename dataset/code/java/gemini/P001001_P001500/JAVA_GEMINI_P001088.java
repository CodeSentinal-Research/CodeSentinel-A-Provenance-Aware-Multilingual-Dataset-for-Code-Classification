import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int src = sc.nextInt(), k = sc.nextInt();
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            dist[src] = 0;
            Queue<Integer> q = new LinkedList<>();
            q.offer(src);

            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.offer(v);
                    }
                }
            }
            int count = 0;
            for (int d : dist) if (d == k) count++;
            System.out.println(count);
        }
        sc.close();
    }
}