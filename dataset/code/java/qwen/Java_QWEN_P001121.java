import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        
        int[] degree = new int[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
            degree[u]++;
            degree[v]++;
        }
        
        Queue<Integer> leaves = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (degree[i] <= 1) leaves.offer(i);
        }
        
        List<Integer> centers = new ArrayList<>();
        int remaining = n;
        while (remaining > 2) {
            int size = leaves.size();
            remaining -= size;
            for (int i = 0; i < size; i++) {
                int u = leaves.poll();
                for (int v : adj.get(u)) {
                    degree[v]--;
                    if (degree[v] == 1) leaves.offer(v);
                }
            }
        }
        
        while (!leaves.isEmpty()) centers.add(leaves.poll());
        Collections.sort(centers);
        for (int c : centers) System.out.print(c + " ");
    }
}
