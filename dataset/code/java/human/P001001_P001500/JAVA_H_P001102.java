//Minimum Cost to Connect All Cities
//Minimum Spanning Tree using Kruskal's Algorithm and Disjoint Set Union (DSU)
import java.util.*;

import java.util.*;

class Solution {

    // Disjoint Set Union (Union-Find)
    static class DSU {
        int[] parent, rank;

        DSU(int n) {
            parent = new int[n + 1];
            rank = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }

        boolean union(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if (pa == pb) return false;

            if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else if (rank[pb] < rank[pa]) {
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
            return true;
        }
    }

    public int minimumCost(int n, int[][] connections) {
        Arrays.sort(connections, (a, b) -> a[2] - b[2]);

        DSU dsu = new DSU(n);
        int cost = 0;
        int edgesUsed = 0;

        for (int[] edge : connections) {
            if (dsu.union(edge[0], edge[1])) {
                cost += edge[2];
                edgesUsed++;
            }
        }

        return edgesUsed == n - 1 ? cost : -1;
    }
}
