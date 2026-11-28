import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int t = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
        }
        
        // Topological Sort
        int[] inDegree = new int[n+1];
        for(int u=1; u<=n; u++) {
            for(int v : adj.get(u)) {
                inDegree[v]++;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            if(inDegree[i] == 0) q.offer(i);
        }
        
        List<Integer> topo = new ArrayList<>();
        while(!q.isEmpty()) {
            int u = q.poll();
            topo.add(u);
            for(int v : adj.get(u)) {
                inDegree[v]--;
                if(inDegree[v] == 0) q.offer(v);
            }
        }
        
        long[] dp = new long[n+1];
        dp[s] = 1;
        
        for(int u : topo) {
            for(int v : adj.get(u)) {
                dp[v] += dp[u];
            }
        }
        
        System.out.println(dp[t]);
    }
}
