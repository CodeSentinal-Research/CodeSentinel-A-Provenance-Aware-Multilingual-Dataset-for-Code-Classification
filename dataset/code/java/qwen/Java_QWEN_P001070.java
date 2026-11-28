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
        
        int[] color = new int[n+1];
        Arrays.fill(color, -1);
        boolean isBipartite = true;
        
        for(int i=1; i<=n; i++) {
            if(color[i] == -1) {
                Queue<Integer> q = new LinkedList<>();
                q.offer(i);
                color[i] = 0;
                
                while(!q.isEmpty()) {
                    int u = q.poll();
                    for(int v : adj.get(u)) {
                        if(color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.offer(v);
                        } else if(color[v] == color[u]) {
                            isBipartite = false;
                            break;
                        }
                    }
                    if(!isBipartite) break;
                }
            }
            if(!isBipartite) break;
        }
        
        System.out.println(isBipartite ? "YES" : "NO");
    }
}
