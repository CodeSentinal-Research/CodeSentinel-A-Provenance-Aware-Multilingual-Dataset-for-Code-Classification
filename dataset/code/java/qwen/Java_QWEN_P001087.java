import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        if(m != n-1) {
            System.out.println("NO");
            return;
        }
        
        boolean[] visited = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        visited[1] = true;
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
        
        System.out.println(count == n ? "YES" : "NO");
    }
}
