public class Solution {
    private int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length + 1;
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int[] e : edges) {
            int ru = find(parent, e[0]), rv = find(parent, e[1]);
            if (ru == rv) return e;
            parent[ru] = rv;
        }
        return new int[0];
    }
}