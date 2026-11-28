import java.util.*;

public class Solution {
    private static int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

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
            Arrays.sort(edges, (a, b) -> {
                if (a[2] != b[2]) return Integer.compare(a[2], b[2]);
                int mina = Math.min(a[0], a[1]), minb = Math.min(b[0], b[1]);
                if (mina != minb) return Integer.compare(mina, minb);
                return Integer.compare(Math.max(a[0], a[1]), Math.max(b[0], b[1]));
            });
            int[] parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;

            List<int[]> mst = new ArrayList<>();
            for (int[] e : edges) {
                int ru = find(parent, e[0]), rv = find(parent, e[1]);
                if (ru != rv) {
                    parent[ru] = rv;
                    mst.add(new int[]{Math.min(e[0], e[1]), Math.max(e[0], e[1]), e[2]});
                    if (mst.size() == n - 1) break;
                }
            }
            for (int[] e : mst) {
                System.out.println(e[0] + " " + e[1] + " " + e[2]);
            }
        }
        sc.close();
    }
}