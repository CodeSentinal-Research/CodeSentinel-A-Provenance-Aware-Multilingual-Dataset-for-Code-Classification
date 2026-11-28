import java.util.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int type;
        int u, v;

        Edge(int type, int u, int v) {
            this.type = type;
            this.u = u;
            this.v = v;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.type, o.type);
        }
    }

    static int N, M;
    static int[] parent;
    static int[] size;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static boolean union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    static void swap(int x, int y) {
        int temp = parent[x];
        parent[x] = parent[y];
        parent[y] = temp;
        temp = size[x];
        size[x] = size[y];
        size[y] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        parent = new int[N + 1];
        size = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int type = sc.nextInt();
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(new Edge(type, u, v));
        }
        Collections.sort(edges);
        int ans = 0;
        for (Edge edge : edges) {
            if (union(edge.u, edge.v)) ans++;
        }
        for (int i = 1; i <= N; i++) {
            if (find(i) == find(1)) {
                System.out.println(ans);
                return;
            }
        }
        System.out.println(-1);
    }
}
