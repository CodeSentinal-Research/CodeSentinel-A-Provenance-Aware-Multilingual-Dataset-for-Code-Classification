import java.util.*;

public class Solution {
    private void dfs(int node, int target, int[][] graph, List<Integer> path, List<List<Integer>> res) {
        if (node == target) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int next : graph[node]) {
            path.add(next);
            dfs(next, target, graph, path, res);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(0, graph.length - 1, graph, path, res);
        return res;
    }
}