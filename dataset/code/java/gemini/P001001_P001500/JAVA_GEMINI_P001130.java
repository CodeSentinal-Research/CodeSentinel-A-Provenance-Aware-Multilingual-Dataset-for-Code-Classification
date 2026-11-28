public class Solution {
    private int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    private void union(int[] parent, int i, int j) {
        int ri = find(parent, i), rj = find(parent, j);
        if (ri != rj) parent[ri] = rj;
    }

    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int[] parent = new int[4 * n * n];
        for (int i = 0; i < 4 * n * n; i++) parent[i] = i;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int root = 4 * (r * n + c);
                char val = grid[r].charAt(c);
                if (val != '/') {
                    union(parent, root + 0, root + 1);
                    union(parent, root + 2, root + 3);
                }
                if (val != '\\') {
                    union(parent, root + 0, root + 3);
                    union(parent, root + 1, root + 2);
                }
                if (r + 1 < n) {
                    union(parent, root + 2, 4 * ((r + 1) * n + c) + 0);
                }
                if (c + 1 < n) {
                    union(parent, root + 1, 4 * (r * n + c + 1) + 3);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (find(parent, i) == i) count++;
        }
        return count;
    }
}