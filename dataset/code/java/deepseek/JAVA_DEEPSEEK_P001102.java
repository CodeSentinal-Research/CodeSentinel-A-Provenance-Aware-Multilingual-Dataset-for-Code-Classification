import java.util.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int u, v, cost;
        Edge(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }
        public int compareTo(Edge other) {
            return cost - other.cost;
        }
    }
    static int N, M;
    static int[] parent;
    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    static boolean union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) parent[i] = i;
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int cost = scanner.nextInt();
            edges.add(new Edge(u, v, cost));
        }
        edges.sort(Comparator.naturalOrder());
        int totalCost = 0;
        for (Edge edge : edges) {
            if (union(edge.u, edge.v)) totalCost += edge.cost;
        }
        for (int i = 1; i <= N; i++) {
            if (find(i) != find(i - 1)) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(totalCost);
    }
}
