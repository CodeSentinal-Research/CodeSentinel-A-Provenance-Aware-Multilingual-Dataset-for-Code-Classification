import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[][] edges = new int[m][3];
        for(int i=0; i<m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }
        
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        
        int[] parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;
        
        long totalWeight = 0;
        int count = 0;
        
        for(int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if(find(parent, u) != find(parent, v)) {
                union(parent, u, v);
                totalWeight += w;
                count++;
                if(count == n-1) break;
            }
        }
        
        System.out.println(totalWeight);
    }
    
    static int find(int[] parent, int i) {
        if(parent[i] != i) parent[i] = find(parent, parent[i]);
        return parent[i];
    }
    
    static void union(int[] parent, int i, int j) {
        parent[find(parent, i)] = find(parent, j);
    }
}
