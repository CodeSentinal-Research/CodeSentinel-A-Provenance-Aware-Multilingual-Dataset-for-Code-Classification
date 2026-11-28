import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            long[][] cap = new long[n][n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                long c = sc.nextLong();
                cap[u][v] += c;
            }
            int src = sc.nextInt(), sink = sc.nextInt();
            long flow = 0;

            while (true) {
                int[] parent = new int[n];
                Arrays.fill(parent, -1);
                parent[src] = -2;
                Queue<Integer> q = new LinkedList<>();
                q.offer(src);
                long[] curCap = new long[n];
                curCap[src] = Long.MAX_VALUE;

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
                flow += aug;
                int curr = sink;
                while (curr != src) {
                    int p = parent[curr];
                    cap[p][curr] -= aug;
                    cap[curr][p] += aug;
                    curr = p;
                }
            }
            System.out.println(flow);
        }
        sc.close();
    }
}