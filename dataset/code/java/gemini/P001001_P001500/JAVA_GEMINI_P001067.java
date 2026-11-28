import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
            }
            int src = sc.nextInt();
            boolean[] vis = new boolean[n];
            Queue<Integer> q = new LinkedList<>();
            q.offer(src);
            vis[src] = true;
            int count = 0;
            while (!q.isEmpty()) {
                int u = q.poll();
                count++;
                for (int v : adj.get(u)) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                    }
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}