import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        int[] degree = new int[n+1];
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
            degree[u]++;
            degree[v]++;
        }
        
        int oddCount = 0;
        for(int i=1; i<=n; i++) {
            if(degree[i] % 2 != 0) oddCount++;
        }
        
        // Check connectivity
        boolean[] visited = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            if(degree[i] > 0) {
                q.offer(i);
                visited[i] = true;
                break;
            }
        }
        int count = 0;
        while(!q.isEmpty()) {
            int u = q.poll();
            count++;
            for(int v : adj.get(u)) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.offer(v);
                }
            }
        }
        
        if(oddCount == 0 || oddCount == 2) {
             System.out.println("1"); // Placeholder
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
