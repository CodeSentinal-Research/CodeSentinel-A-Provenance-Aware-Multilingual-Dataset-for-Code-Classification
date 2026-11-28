public class Solution {
    private int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    public int maxNumEdgesToRemove(int n, int[][] edges) {
        int[] parentA = new int[n + 1];
        int[] parentB = new int[n + 1];
        for (int i = 0; i <= n; i++) { parentA[i] = i; parentB[i] = i; }

        int used = 0, edgesA = 0, edgesB = 0;

        for (int[] e : edges) {
            if (e[0] == 3) {
                int rA1 = find(parentA, e[1]), rA2 = find(parentA, e[2]);
                int rB1 = find(parentB, e[1]), rB2 = find(parentB, e[2]);
                if (rA1 != rA2 || rB1 != rB2) {
                    parentA[rA1] = rA2;
                    parentB[rB1] = rB2;
                    used++;
                    edgesA++;
                    edgesB++;
                }
            }
        }

        for (int[] e : edges) {
            if (e[0] == 1) {
                int r1 = find(parentA, e[1]), r2 = find(parentA, e[2]);
                if (r1 != r2) {
                    parentA[r1] = r2;
                    used++;
                    edgesA++;
                }
            } else if (e[0] == 2) {
                int r1 = find(parentB, e[1]), r2 = find(parentB, e[2]);
                if (r1 != r2) {
                    parentB[r1] = r2;
                    used++;
                    edgesB++;
                }
            }
        }

        return (edgesA == n - 1 && edgesB == n - 1) ? edges.length - used : -1;
    }
}