import java.util.*;
public class Main {
    static int maxDist, endNode;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<n-1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        maxDist = 0;
        dfs(1, -1, 0, adj);
        int start = endNode;
        
        maxDist = 0;
        dfs(start, -1, 0, adj);
        
        System.out.println(maxDist);
    }
    
    static void dfs(int u, int parent, int dist, List<List<Integer>> adj) {
        if(dist > maxDist) {
            maxDist = dist;
            endNode = u;
        }
        for(int v : adj.get(u)) {
            if(v != parent) dfs(v, u, dist+1, adj);
        }
    }
}
