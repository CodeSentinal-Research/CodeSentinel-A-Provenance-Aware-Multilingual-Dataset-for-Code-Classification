import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            long[][] dist = new long[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], Long.MAX_VALUE);
                dist[i][i] = 0;
            }
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt(), w = sc.nextInt();
                dist[u][v] = Math.min(dist[u][v], w);
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][k] != Long.MAX_VALUE && dist[k][j] != Long.MAX_VALUE) {
                            if (dist[i][k] + dist[k][j] < dist[i][j]) {
                                dist[i][j] = dist[i][k] + dist[k][j];
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print((dist[i][j] == Long.MAX_VALUE ? -1 : dist[i][j]) + (j == n - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}