import java.util.*;
public class Main {
    static int[] parent;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        int[][] edges = new int[m][3];
        for (int i = 0; i < m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        
        long cost = 0;
        int count = 0;
        for (int[] e : edges) {
            if (find(e[0]) != find(e[1])) {
                union(e[0], e[1]);
                cost += e[2];
                count++;
                if (count == n - 1) break;
            }
        }
        System.out.println(count == n - 1 ? cost : -1);
    }
    static int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    static void union(int i, int j) {
        parent[find(i)] = find(j);
    }
}
