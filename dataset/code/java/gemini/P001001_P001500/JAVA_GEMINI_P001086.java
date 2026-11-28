import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < k; i++) {
                int s = sc.nextInt();
                dist[s] = 0;
                q.offer(s);
            }
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.offer(v);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print(dist[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}