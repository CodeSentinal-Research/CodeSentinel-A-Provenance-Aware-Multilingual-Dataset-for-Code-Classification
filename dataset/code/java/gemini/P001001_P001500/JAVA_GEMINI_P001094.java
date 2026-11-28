import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    private static boolean bpm(int u, int n, boolean[][] adj, boolean[] seen, int[] matchR) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !seen[v]) {
                seen[v] = true;
                if (matchR[v] < 0 || bpm(matchR[v], n, adj, seen, matchR)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt(), k = sc.nextInt();
            boolean[][] adj = new boolean[m][n];
            for (int i = 0; i < k; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj[u][v] = true;
            }
            int[] matchR = new int[n];
            Arrays.fill(matchR, -1);
            int res = 0;
            for (int u = 0; u < m; u++) {
                boolean[] seen = new boolean[n];
                if (bpm(u, n, adj, seen, matchR)) res++;
            }
            System.out.println(res);
        }
        sc.close();
    }
}