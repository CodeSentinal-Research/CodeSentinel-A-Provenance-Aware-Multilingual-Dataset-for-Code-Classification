import java.util.*;
public class Main {
    static boolean found;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        boolean[][] adj = new boolean[n+1][n+1];
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u][v] = true;
            adj[v][u] = true;
        }
        
        found = false;
        boolean[] visited = new boolean[n+1];
        visited[1] = true;
        dfs(1, n, adj, visited, 1);
        
        System.out.println(found ? "YES" : "NO");
    }
    
    static void dfs(int u, int n, boolean[][] adj, boolean[] visited, int count) {
        if(count == n) {
            found = true;
            return;
        }
        for(int v=1; v<=n; v++) {
            if(adj[u][v] && !visited[v]) {
                visited[v] = true;
                dfs(v, n, adj, visited, count+1);
                visited[v] = false;
                if(found) return;
            }
        }
    }
}
