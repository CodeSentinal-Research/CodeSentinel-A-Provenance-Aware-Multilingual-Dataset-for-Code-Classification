import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        long[][] dist = new long[n+1][n+1];
        for(long[] row : dist) Arrays.fill(row, Long.MAX_VALUE / 2);
        for(int i=1; i<=n; i++) dist[i][i] = 0;
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][j] >= Long.MAX_VALUE / 2) System.out.print(-1 + " ");
                else System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }
}
