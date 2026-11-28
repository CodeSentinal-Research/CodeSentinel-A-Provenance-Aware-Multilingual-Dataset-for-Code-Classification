import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        List<List<Integer>> radj = new ArrayList<>();
        for(int i=0; i<=n; i++) {
            adj.add(new ArrayList<>());
            radj.add(new ArrayList<>());
        }
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            radj.get(v).add(u);
        }
        
        // Kosaraju's or simple DFS from last finished node
        boolean[] visited = new boolean[n+1];
        Stack<Integer> stack = new Stack<>();
        
        for(int i=1; i<=n; i++) {
            if(!visited[i]) dfs(i, adj, visited, stack);
        }
        
        int mother = stack.pop();
        Arrays.fill(visited, false);
        dfs(mother, radj, visited, new Stack<>());
        
        boolean allVisited = true;
        for(int i=1; i<=n; i++) {
            if(!visited[i]) allVisited = false;
        }
        
        System.out.println(allVisited ? mother : -1);
    }
    
    static void dfs(int u, List<List<Integer>> adj, boolean[] visited, Stack<Integer> stack) {
        visited[u] = true;
        for(int v : adj.get(u)) {
            if(!visited[v]) dfs(v, adj, visited, stack);
        }
        stack.push(u);
    }
}
