import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            long[][] cap = new long[n][n];
            int[][] edges = new int[m][3];
            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                edges[i][2] = sc.nextInt();
                cap[edges[i][0]][edges[i][1]] += edges[i][2];
            }
            int src = sc.nextInt(), sink = sc.nextInt();

            while (true) {
                int[] parent = new int[n];
                Arrays.fill(parent, -1);
                parent[src] = -2;
                long[] curCap = new long[n];
                curCap[src] = Long.MAX_VALUE;
                Queue<Integer> q = new LinkedList<>();
                q.offer(src);

                while (!q.isEmpty()) {
                    int u = q.poll();
                    if (u == sink) break;
                    for (int v = 0; v < n; v++) {
                        if (parent[v] == -1 && cap[u][v] > 0) {
                            parent[v] = u;
                            curCap[v] = Math.min(curCap[u], cap[u][v]);
                            q.offer(v);
                        }
                    }
                }
                if (parent[sink] == -1) break;
                long aug = curCap[sink];
                int curr = sink;
                while (curr != src) {
                    int p = parent[curr];
                    cap[p][curr] -= aug;
                    cap[curr][p] += aug;
                    curr = p;
                }
            }

            boolean[] vis = new boolean[n];
            vis[src] = true;
            Queue<Integer> q = new LinkedList<>();
            q.offer(src);
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v = 0; v < n; v++) {
                    if (!vis[v] && cap[u][v] > 0) {
                        vis[v] = true;
                        q.offer(v);
                    }
                }
            }
            long cut = 0;
            for (int[] e : edges) {
                if (vis[e[0]] && !vis[e[1]]) cut += e[2];
            }
            System.out.println(cut);
        }
        sc.close();
    }
}