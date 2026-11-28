import java.util.*;

public class Main {
    static class UnionFind {
        int[] parent;
        int[] size;
        int[][] edges;
        int N;

        public UnionFind(int N) {
            this.N = N;
            parent = new int[N + 1];
            size = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                parent[i] = i;
                size[i] = 1;
            }
            edges = new int[N][3];
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public void union(int x, int y, int z) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (size[x] < size[y]) {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                parent[y] = x;
                size[x] += size[y];
            }
            edges[z - 1] = new int[]{x, y, z};
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        UnionFind unionFind = new UnionFind(N);
        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            unionFind.union(x, y, i + 1);
        }
        for (int i = 0; i < N - 1; i++) {
            int x = unionFind.edges[i][0];
            int y = unionFind.edges[i][1];
            int z = unionFind.edges[i][2];
            if (unionFind.find(x) != unionFind.find(y)) {
                System.out.println(x + " " + y);
                break;
            }
        }
    }
}
