import java.util.*;

public class Solution {
    private static int timer = 0;

    private static void dfs(int u, int p, List<List<Integer>> adj, int[] tin, int[] low, boolean[] isAp) {
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int v : adj.get(u)) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u, adj, tin, low, isAp);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] >= tin[u] && p != -1) isAp[u] = true;
                children++;
            }
        }
        if (p == -1 && children > 1) isAp[u] = true;
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
            boolean[] isAp = new boolean[n];
            Arrays.fill(tin, -1);
            Arrays.fill(low, -1);
            timer = 0;
            for (int i = 0; i < n; i++) {
                if (tin[i] == -1) dfs(i, -1, adj, tin, low, isAp);
            }
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (isAp[i]) res.add(i);
            }
            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i == res.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}