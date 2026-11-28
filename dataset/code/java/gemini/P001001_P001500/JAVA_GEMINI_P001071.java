import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

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
            }
            boolean[] vis = new boolean[n];
            int lastV = 0;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(i, adj, vis);
                    lastV = i;
                }
            }
            Arrays.fill(vis, false);
            dfs(lastV, adj, vis);
            boolean allVis = true;
            for (boolean b : vis) if (!b) { allVis = false; break; }
            System.out.println(allVis ? lastV : -1);
        }
        sc.close();
    }
}