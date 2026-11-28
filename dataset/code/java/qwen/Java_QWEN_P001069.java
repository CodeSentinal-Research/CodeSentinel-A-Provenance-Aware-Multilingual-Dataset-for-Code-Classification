import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        
        List<List<int[]>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(new int[]{v, w});
        }
        
        // Topological Sort
        int[] inDegree = new int[n+1];
        for(int u=1; u<=n; u++) {
            for(int[] edge : adj.get(u)) {
                inDegree[edge[0]]++;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            if(inDegree[i] == 0) q.offer(i);
        }
        
        List<Integer> topo = new ArrayList<>();
        while(!q.isEmpty()) {
            int u = q.poll();
            topo.add(u);
            for(int[] edge : adj.get(u)) {
                inDegree[edge[0]]--;
                if(inDegree[edge[0]] == 0) q.offer(edge[0]);
            }
        }
        
        long[] dist = new long[n+1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[s] = 0;
        
        for(int u : topo) {
            if(dist[u] == Long.MAX_VALUE) continue;
            for(int[] edge : adj.get(u)) {
                int v = edge[0];
                int w = edge[1];
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for(int i=1; i<=n; i++) {
            if(dist[i] == Long.MAX_VALUE) System.out.print(-1 + " ");
            else System.out.print(dist[i] + " ");
        }
    }
}
