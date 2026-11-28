import java.util.*;
public class Main {
    static int[] disc, low;
    static boolean[] visited, isArticulation;
    static int time;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        disc = new int[n+1];
        low = new int[n+1];
        visited = new boolean[n+1];
        isArticulation = new boolean[n+1];
        time = 0;
        
        for(int i=1; i<=n; i++) {
            if(!visited[i]) dfs(i, -1, adj);
        }
        
        List<Integer> points = new ArrayList<>();
        for(int i=1; i<=n; i++) {
            if(isArticulation[i]) points.add(i);
        }
        
        if(points.isEmpty()) System.out.println("NONE");
        else {
            for(int p : points) System.out.print(p + " ");
        }
    }
    
    static void dfs(int u, int parent, List<List<Integer>> adj) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;
        
        for(int v : adj.get(u)) {
            if(v == parent) continue;
            if(!visited[v]) {
                children++;
                dfs(v, u, adj);
                low[u] = Math.min(low[u], low[v]);
                
                if(parent == -1 && children > 1) isArticulation[u] = true;
                if(parent != -1 && low[v] >= disc[u]) isArticulation[u] = true;
            } else {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
}
