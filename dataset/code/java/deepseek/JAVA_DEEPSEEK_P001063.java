import java.util.*;

public class Main {
    static class Edge {
        int u, v;
        Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    static int N, M;
    static List<Edge> edges = new ArrayList<>();
    static int[] degree = new int[N + 1];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(new Edge(u, v));
            degree[u]++;
        }
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (degree[i] == 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
