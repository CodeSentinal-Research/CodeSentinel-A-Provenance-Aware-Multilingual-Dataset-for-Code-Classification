import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i<n-1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        // Find centers by removing leaves layer by layer
        List<Integer> leaves = new ArrayList<>();
        int[] degree = new int[n+1];
        for(int i=1; i<=n; i++) {
            degree[i] = adj.get(i).size();
            if(degree[i] <= 1) leaves.add(i);
        }
        
        int remaining = n;
        while(remaining > 2) {
            remaining -= leaves.size();
            List<Integer> newLeaves = new ArrayList<>();
            for(int u : leaves) {
                for(int v : adj.get(u)) {
                    degree[v]--;
                    if(degree[v] == 1) newLeaves.add(v);
                }
            }
            leaves = newLeaves;
        }
        
        Collections.sort(leaves);
        for(int x : leaves) System.out.print(x + " ");
    }
}
