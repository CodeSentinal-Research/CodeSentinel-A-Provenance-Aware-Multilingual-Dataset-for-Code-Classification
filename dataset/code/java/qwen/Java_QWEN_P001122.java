import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        int[] outDegree = new int[n + 1];
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            outDegree[u]++;
        }
        
        // States: 0=unvisited, 1=visiting, 2=visited
        int[] state = new int[n + 1];
        List<Integer> safe = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, adj, state)) safe.add(i);
        }
        
        for (int s : safe) System.out.print(s + " ");
    }
    
    static boolean dfs(int u, List<List<Integer>> adj, int[] state) {
        if (state[u] == 1) return false;
        if (state[u] == 2) return true;
        
        state[u] = 1;
        for (int v : adj.get(u)) {
            if (!dfs(v, adj, state)) return false;
        }
        state[u] = 2;
        return true;
    }
}
