import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=l; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
        }
        
        int[] matchR = new int[r+1];
        Arrays.fill(matchR, -1);
        
        int result = 0;
        for(int u=1; u<=l; u++) {
            boolean[] visited = new boolean[r+1];
            if(bpm(u, adj, visited, matchR)) result++;
        }
        
        System.out.println(result);
    }
    
    static boolean bpm(int u, List<List<Integer>> adj, boolean[] visited, int[] matchR) {
        for(int v : adj.get(u)) {
            if(!visited[v]) {
                visited[v] = true;
                if(matchR[v] == -1 || bpm(matchR[v], adj, visited, matchR)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
}
