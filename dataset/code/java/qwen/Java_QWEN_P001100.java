import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        
        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("ADD")) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                union(u, v);
            } else if(op.equals("QUERY")) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                System.out.println(find(u) == find(v) ? "YES" : "NO");
            }
        }
    }
    
    static int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
