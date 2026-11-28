import java.util.*;
public class Main {
    static int v, e, m;
    static List<List<Integer>> adj;
    static int[] color;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v = sc.nextInt();
        e = sc.nextInt();
        m = sc.nextInt();
        
        adj = new ArrayList<>();
        for(int i=0; i<=v; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<e; i++) {
            int u = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(w);
            adj.get(w).add(u);
        }
        
        color = new int[v+1];
        System.out.println(solve(1) ? "YES" : "NO");
    }
    
    static boolean solve(int node) {
        if(node > v) return true;
        for(int c=1; c<=m; c++) {
            if(isSafe(node, c)) {
                color[node] = c;
                if(solve(node+1)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
    static boolean isSafe(int node, int c) {
        for(int neighbor : adj.get(node)) {
            if(color[neighbor] == c) return false;
        }
        return true;
    }
}
