import java.util.*;
public class Main {
    static int[][] parent;
    static int[] depth;
    static final int LOG = 20;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<n-1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        parent = new int[n+1][LOG];
        depth = new int[n+1];
        dfs(1, -1, 0, adj);
        
        for(int k=1; k<LOG; k++) {
            for(int i=1; i<=n; i++) {
                if(parent[i][k-1] != -1) {
                    parent[i][k] = parent[parent[i][k-1]][k-1];
                } else {
                    parent[i][k] = -1;
                }
            }
        }
        
        for(int i=0; i<q; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            System.out.println(lca(u, v));
        }
    }
    
    static void dfs(int u, int p, int d, List<List<Integer>> adj) {
        parent[u][0] = p;
        depth[u] = d;
        for(int v : adj.get(u)) {
            if(v != p) dfs(v, u, d+1, adj);
        }
    }
    
    static int lca(int u, int v) {
        if(depth[u] < depth[v]) {
            int t = u; u = v; v = t;
        }
        int diff = depth[u] - depth[v];
        for(int k=0; k<LOG; k++) {
            if((diff & (1<<k)) != 0) {
                u = parent[u][k];
            }
        }
        if(u == v) return u;
        for(int k=LOG-1; k>=0; k--) {
            if(parent[u][k] != parent[v][k]) {
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        return parent[u][0];
    }
}
