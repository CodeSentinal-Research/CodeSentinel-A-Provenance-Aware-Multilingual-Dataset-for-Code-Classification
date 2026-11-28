public class Solution {
    private int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        int provinces = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int ri = find(parent, i), rj = find(parent, j);
                    if (ri != rj) {
                        parent[ri] = rj;
                        provinces--;
                    }
                }
            }
        }
        return provinces;
    }
}