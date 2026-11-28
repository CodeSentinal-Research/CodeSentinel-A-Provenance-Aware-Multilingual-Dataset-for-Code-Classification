import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] edges = new int[m][3];
            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                edges[i][2] = sc.nextInt();
            }
            int src = sc.nextInt();
            long[] dist = new long[n];
            Arrays.fill(dist, Long.MAX_VALUE);
            dist[src] = 0;

            for (int iter = 0; iter < n - 1; iter++) {
                for (int[] e : edges) {
                    int u = e[0], v = e[1], w = e[2];
                    if (dist[u] != Long.MAX_VALUE && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            boolean negCycle = false;
            for (int[] e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != Long.MAX_VALUE && dist[u] + w < dist[v]) {
                    negCycle = true;
                    break;
                }
            }

            if (negCycle) {
                System.out.println("NEGATIVE CYCLE");
            } else {
                for (int i = 0; i < n; i++) {
                    System.out.print((dist[i] == Long.MAX_VALUE ? -1 : dist[i]) + (i == n - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}