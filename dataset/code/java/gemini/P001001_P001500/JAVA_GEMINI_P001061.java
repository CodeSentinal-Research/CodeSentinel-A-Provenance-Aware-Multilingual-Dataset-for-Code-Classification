import java.util.*;

public class Solution {
    private static boolean dfs(int u, List<List<Integer>> adj, int[] vis) {
        vis[u] = 1;
        for (int v : adj.get(u)) {
            if (vis[v] == 1) return true;
            if (vis[v] == 0 && dfs(v, adj, vis)) return true;
        }
        vis[u] = 2;
        return false;
    }

    public static boolean hasCycle(int n, List<List<Integer>> adj) {
        int[] vis = new int[n];
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0 && dfs(i, adj, vis)) return true;
        }
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
            }
            System.out.println(hasCycle(n, adj) ? "YES" : "NO");
        }
        sc.close();
    }
}