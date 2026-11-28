import java.util.*;

public class Solution {
    private static boolean dfs(int u, int count, int n, List<List<Integer>> adj, boolean[] vis) {
        if (count == n) {
            return adj.get(u).contains(0);
        }
        vis[u] = true;
        for (int v : adj.get(u)) {
            if (!vis[v] && dfs(v, count + 1, n, adj, vis)) return true;
        }
        vis[u] = false;
        return false;
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
            boolean[] vis = new boolean[n];
            System.out.println(dfs(0, 1, n, adj, vis) ? "YES" : "NO");
        }
        sc.close();
    }
}