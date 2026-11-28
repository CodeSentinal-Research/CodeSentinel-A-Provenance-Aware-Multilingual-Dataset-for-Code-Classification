import java.util.*;
public class Main {
    static int[] disc, low;
    static boolean[] visited;
    static int time;
    static List<int[]> bridges;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        disc = new int[n + 1];
        low = new int[n + 1];
        visited = new boolean[n + 1];
        bridges = new ArrayList<>();
        time = 0;
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i, -1, adj);
        }
        
        if (bridges.isEmpty()) System.out.println("NONE");
        else {
            bridges.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
            for (int[] b : bridges) System.out.println(b[0] + " " + b[1]);
        }
    }
    
    static void dfs(int u, int parent, List<List<Integer>> adj) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        
        for (int v : adj.get(u)) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u, adj);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.add(new int[]{Math.min(u, v), Math.max(u, v)});
                }
            } else {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
}
