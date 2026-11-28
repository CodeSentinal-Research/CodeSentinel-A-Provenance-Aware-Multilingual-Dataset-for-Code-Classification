import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;
        
        boolean cycle = false;
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            if(find(u) == find(v)) cycle = true;
            else union(u, v);
        }
        
        System.out.println(cycle ? "YES" : "NO");
    }
    
    static int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
