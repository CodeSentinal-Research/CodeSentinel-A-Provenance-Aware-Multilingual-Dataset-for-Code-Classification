public class TreeAncestor {
    private int[][] up;
    private int LOG = 20;

    public TreeAncestor(int n, int[] parent) {
        up = new int[n][LOG];
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                } else {
                    up[i][j] = -1;
                }
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            // If current bit is set, multiply base into result
            if (((k >> j) & 1) == 1) {
                node = up[node][j];
                if (node == -1) break;
            }
        }
        return node;
    }
}