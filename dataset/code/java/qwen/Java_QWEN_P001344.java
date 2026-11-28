import java.util.*;
public class Main {
    static int v, e;
    static List<List<Integer>> adj;
    static List<List<Integer>> allPaths;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v = sc.nextInt();
        e = sc.nextInt();
        
        adj = new ArrayList<>();
        for(int i=0; i<v; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<e; i++) {
            int u = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(w);
        }
        
        allPaths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(0, v-1, path);
        
        for(List<Integer> p : allPaths) {
            System.out.println(p);
        }
    }
    
    static void dfs(int node, int target, List<Integer> path) {
        if(node == target) {
            allPaths.add(new ArrayList<>(path));
            return;
        }
        for(int next : adj.get(node)) {
            path.add(next);
            dfs(next, target, path);
            path.remove(path.size()-1);
        }
    }
}
