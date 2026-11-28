import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int t = sc.nextInt();
        
        int[][] capacity = new int[n+1][n+1];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int c = sc.nextInt();
            capacity[u][v] += c;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        // Min Cut = Max Flow
        System.out.println(maxFlow(s, t, n, capacity, adj));
    }
    
    static int maxFlow(int s, int t, int n, int[][] capacity, List<List<Integer>> adj) {
        int flow = 0;
        int[] parent = new int[n+1];
        
        while(bfs(s, t, parent, capacity, adj, n)) {
            int pathFlow = Integer.MAX_VALUE;
            for(int v=t; v!=s; v=parent[v]) {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, capacity[u][v]);
            }
            
            for(int v=t; v!=s; v=parent[v]) {
                int u = parent[v];
                capacity[u][v] -= pathFlow;
                capacity[v][u] += pathFlow;
            }
            flow += pathFlow;
        }
        return flow;
    }
    
    static boolean bfs(int s, int t, int[] parent, int[][] capacity, List<List<Integer>> adj, int n) {
        boolean[] visited = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        q.offer(s);
        visited[s] = true;
        parent[s] = -1;
        
        while(!q.isEmpty()) {
            int u = q.poll();
            for(int v : adj.get(u)) {
                if(!visited[v] && capacity[u][v] > 0) {
                    visited[v] = true;
                    parent[v] = u;
                    if(v == t) return true;
                    q.offer(v);
                }
            }
        }
        return false;
    }
}
