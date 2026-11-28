import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        
        int[][] edges = new int[m][3];
        for(int i=0; i<m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }
        
        long[] dist = new long[n+1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[s] = 0;
        
        for(int i=0; i<n-1; i++) {
            for(int[] e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u] != Long.MAX_VALUE && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Check negative cycle
        for(int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u] != Long.MAX_VALUE && dist[u] + w < dist[v]) {
                System.out.println("NEGATIVE CYCLE");
                return;
            }
        }
        
        for(int i=1; i<=n; i++) {
            if(dist[i] == Long.MAX_VALUE) System.out.print(-1 + " ");
            else System.out.print(dist[i] + " ");
        }
    }
}
