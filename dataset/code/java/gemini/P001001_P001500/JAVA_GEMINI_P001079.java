import java.util.*;

public class Solution {
    private static int timer = 0;

    private static void dfs(int u, int p, List<List<Integer>> adj, int[] tin, int[] low, List<int[]> bridges) {
        tin[u] = low[u] = timer++;
        for (int v : adj.get(u)) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u, adj, tin, low, bridges);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.add(new int[]{Math.min(u, v), Math.max(u, v)});
                }
            }
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
            int[] tin = new int[n];
            int[] low = new int[n];
            Arrays.fill(tin, -1);
            Arrays.fill(low, -1);
            List<int[]> bridges = new ArrayList<>();
            timer = 0;
            for (int i = 0; i < n; i++) {
                if (tin[i] == -1) dfs(i, -1, adj, tin, low, bridges);
            }
            bridges.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
            for (int[] b : bridges) {
                System.out.println(b[0] + " " + b[1]);
            }
        }
        sc.close();
    }
}