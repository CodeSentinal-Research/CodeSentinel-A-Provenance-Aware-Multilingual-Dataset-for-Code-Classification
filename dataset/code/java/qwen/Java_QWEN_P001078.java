import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<int[]>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(new int[]{v, w});
            adj.get(v).add(new int[]{u, w});
        }
        
        long[] dist = new long[n+1];
        Arrays.fill(dist, Long.MAX_VALUE);
        boolean[] visited = new boolean[n+1];
        
        dist[1] = 0;
        long totalWeight = 0;
        
        for(int i=0; i<n; i++) {
            int u = -1;
            for(int j=1; j<=n; j++) {
                if(!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
            }
            
            visited[u] = true;
            totalWeight += dist[u];
            
            for(int[] edge : adj.get(u)) {
                int v = edge[0];
                int w = edge[1];
                if(!visited[v] && w < dist[v]) {
                    dist[v] = w;
                }
            }
        }
        
        System.out.println(totalWeight);
    }
}
