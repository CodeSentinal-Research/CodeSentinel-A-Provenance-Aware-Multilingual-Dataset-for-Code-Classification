import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        int[] inDegree = new int[n+1];
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            inDegree[v]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            if(inDegree[i] == 0) q.offer(i);
        }
        
        boolean hasCycle = false;
        int count = 0;
        while(!q.isEmpty()) {
            int u = q.poll();
            count++;
            for(int v : adj.get(u)) {
                inDegree[v]--;
                if(inDegree[v] == 0) q.offer(v);
            }
        }
        
        System.out.println(count == n ? "NO" : "YES");
    }
}
