import java.util.*;
public class Main {
    static int V, E, M;
    static List<List<Integer>> adj;
    static int[] color;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        V = sc.nextInt();
        E = sc.nextInt();
        M = sc.nextInt();
        
        adj = new ArrayList<>();
        for (int i = 0; i <= V; i++) adj.add(new ArrayList<>());
        
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        color = new int[V + 1];
        System.out.println(solve(1) ? "YES" : "NO");
    }
    
    static boolean solve(int v) {
        if (v > V) return true;
        for (int c = 1; c <= M; c++) {
            if (isSafe(v, c)) {
                color[v] = c;
                if (solve(v + 1)) return true;
                color[v] = 0;
            }
        }
        return false;
    }
    
    static boolean isSafe(int v, int c) {
        for (int u : adj.get(v)) {
            if (color[u] == c) return false;
        }
        return true;
    }
}
