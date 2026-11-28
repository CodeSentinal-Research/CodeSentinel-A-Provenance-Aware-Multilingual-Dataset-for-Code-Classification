import java.util.*;

public class Solution {
    private boolean dfs(int u, int[][] graph, int[] color) {
        color[u] = 1;
        for (int v : graph[u]) {
            if (color[v] == 1 || (color[v] == 0 && !dfs(v, graph, color))) {
                return false;
            }
        }
        color[u] = 2;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (color[i] == 2 || (color[i] == 0 && dfs(i, graph, color))) {
                res.add(i);
            }
        }
        return res;
    }
}