import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
            }

            while (q-- > 0) {
                int src = sc.nextInt(), dst = sc.nextInt();
                boolean[] vis = new boolean[n];
                vis[src] = true;
                Queue<Integer> queue = new LinkedList<>();
                queue.offer(src);
                boolean found = false;
                while (!queue.isEmpty()) {
                    int u = queue.poll();
                    if (u == dst) { found = true; break; }
                    for (int v : adj.get(u)) {
                        if (!vis[v]) {
                            vis[v] = true;
                            queue.offer(v);
                        }
                    }
                }
                System.out.println(found ? "YES" : "NO");
            }
        }
        sc.close();
    }
}