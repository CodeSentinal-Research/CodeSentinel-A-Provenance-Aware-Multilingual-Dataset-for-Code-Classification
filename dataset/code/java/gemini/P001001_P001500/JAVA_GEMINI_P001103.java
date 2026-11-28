import java.util.*;

public class Solution {
    private int timer = 0;

    private void dfs(int u, int p, List<List<Integer>> adj, int[] tin, int[] low, List<List<Integer>> bridges) {
        tin[u] = low[u] = timer++;
        for (int v : adj.get(u)) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u, adj, tin, low, bridges);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.add(Arrays.asList(u, v));
                }
            }
        }
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (List<Integer> edge : connections) {
            adj.get(edge.get(0)).add(edge.get(1));
            adj.get(edge.get(1)).add(edge.get(0));
        }
        int[] tin = new int[n];
        int[] low = new int[n];
        Arrays.fill(tin, -1);
        Arrays.fill(low, -1);
        List<List<Integer>> bridges = new ArrayList<>();
        timer = 0;
        dfs(0, -1, adj, tin, low, bridges);
        return bridges;
    }
}