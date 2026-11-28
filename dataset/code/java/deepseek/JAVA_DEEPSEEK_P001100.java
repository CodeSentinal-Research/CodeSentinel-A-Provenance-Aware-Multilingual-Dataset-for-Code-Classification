import java.util.*;

public class Main {
    static class UnionFind {
        int[] parent;
        int[] size;

        public UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public void union(int x, int y) {
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
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < q; i++) {
            int op = scanner.nextInt();
            if (op == 1) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                uf.union(x, y);
            } else {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                if (uf.find(x) == uf.find(y)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
