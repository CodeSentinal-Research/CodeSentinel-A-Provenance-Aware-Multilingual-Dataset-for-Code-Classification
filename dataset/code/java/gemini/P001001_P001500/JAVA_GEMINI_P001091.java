import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), q = sc.nextInt();
            int[] parent = new int[n];
            parent[0] = 0;
            for (int i = 1; i < n; i++) parent[i] = sc.nextInt();

            int[] depth = new int[n];
            for (int i = 1; i < n; i++) {
                int d = 0, curr = i;
                while (curr != 0) {
                    curr = parent[curr];
                    d++;
                }
                depth[i] = d;
            }

            while (q-- > 0) {
                int u = sc.nextInt(), v = sc.nextInt();
                while (depth[u] > depth[v]) u = parent[u];
                while (depth[v] > depth[u]) v = parent[v];
                while (u != v) {
                    u = parent[u];
                    v = parent[v];
                }
                System.out.println(u);
            }
        }
        sc.close();
    }
}