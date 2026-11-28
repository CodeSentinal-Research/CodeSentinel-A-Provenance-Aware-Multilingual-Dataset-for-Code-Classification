import java.util.*;

public class Solution {
    private static void dfs(int u, List<List<Integer>> adj, boolean[] vis) {
        vis[u] = true;
        for (int v : adj.get(u)) {
            if (!vis[v]) dfs(v, adj, vis);
        }
    }

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
            if (m != n - 1) {
                System.out.println("NO");
            } else {
                boolean[] vis = new boolean[n];
                dfs(0, adj, vis);
                boolean allVis = true;
                for (boolean b : vis) if (!b) { allVis = false; break; }
                System.out.println(allVis ? "YES" : "NO");
            }
        }
        sc.close();
    }
}