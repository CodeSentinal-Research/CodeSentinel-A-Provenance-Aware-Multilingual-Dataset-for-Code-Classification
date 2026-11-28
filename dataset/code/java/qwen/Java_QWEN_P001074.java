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
            adj.get(v).add(new int[]{u, w});
        }
        
        long[] dist = new long[n+1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[s] = 0;
        
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));
        pq.offer(new long[]{s, 0});
        
        while(!pq.isEmpty()) {
            long[] curr = pq.poll();
            int u = (int)curr[0];
            long d = curr[1];
            
            if(d > dist[u]) continue;
            
            for(int[] edge : adj.get(u)) {
                int v = edge[0];
                int w = edge[1];
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new long[]{v, dist[v]});
                }
            }
        }
        
        for(int i=1; i<=n; i++) {
            if(dist[i] == Long.MAX_VALUE) System.out.print(-1 + " ");
            else System.out.print(dist[i] + " ");
        }
    }
}
