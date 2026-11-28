import java.util.*;

public class Solution {
    private static void dfs1(int u, List<List<Integer>> adj, boolean[] vis, List<Integer> order) {
        vis[u] = true;
        for (int v : adj.get(u)) {
            if (!vis[v]) dfs1(v, adj, vis, order);
        }
        order.add(u);
    }

    private static void dfs2(int u, List<List<Integer>> radj, boolean[] vis) {
        vis[u] = true;
        for (int v : radj.get(u)) {
            if (!vis[v]) dfs2(v, radj, vis);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            List<List<Integer>> radj = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<>());
                radj.add(new ArrayList<>());
            }
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                radj.get(v).add(u);
            }
            boolean[] vis = new boolean[n];
            List<Integer> order = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (!vis[i]) dfs1(i, adj, vis, order);
            }
            Arrays.fill(vis, false);
            int scc = 0;
            for (int i = order.size() - 1; i >= 0; i--) {
                int u = order.get(i);
                if (!vis[u]) {
                    dfs2(u, radj, vis);
                    scc++;
                }
            }
            System.out.println(scc);
        }
        sc.close();
    }
}