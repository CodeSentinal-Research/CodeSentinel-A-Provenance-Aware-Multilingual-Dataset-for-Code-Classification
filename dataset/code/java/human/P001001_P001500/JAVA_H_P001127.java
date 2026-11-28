import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * 547. Number of Provinces (https://leetcode.com/problems/number-of-provinces/description/)
 */
public class NumberOfProvinces {

//           0 1 2
//        0 [1,1,0]
//        1 [1,1,0]
//        2 [0,0,1]

    /**
     * Same Questions (无向联通图 => 判断连通分量)
     * 323. Number of Connected Components in an Undirected Graph (https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/)
     * 547. Number of Provinces (https://leetcode.com/problems/number-of-provinces/description/)
     */

    /********** Solution 1: Union Find *************/
    /**
     * Time: build uf + iterate over matrix to union = O(2N) = O(N)
     * Space: O(N)
     */
    public int findCircleNum1(int[][] isConnected) {
        int n = isConnected.length;
        UnionFind547 uf = new UnionFind547(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.union(i, j);
                }
            }
        }
        return uf.root;
    }

    /********** Solution 2: Build Adjacency List + DFS ******************/
    /**
     * Time: build adj list + DFS = O(V + E)
     * Space: O(V + E); if no edges, O(V); if all connected, E >= V, O(E);
     */
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        List<Integer>[] adjList = new List[n];
        for (int i = 0; i < n; i++) adjList[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].add(j);
                    adjList[j].add(i);
                }
            }
        }

        int res = 0;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            Deque<Integer> stack = new ArrayDeque<>();
            stack.push(i);
            while (!stack.isEmpty()) {
                int cur = stack.pop();
                for (int nex : adjList[cur]) {
                    if (visited[nex]) continue;
                    visited[nex] = true;
                    stack.push(nex);
                }
            }
            res++;
        }
        return res;
    }
}

class UnionFind547 {

    int[] id, sz;
    int root;

    public UnionFind547(int n) {
        id = new int[n];
        sz = new int[n];
        root = n;
        for (int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    public int find(int p) {
        if (id[p] != p) id[p] = find(id[p]);
        return id[p];
    }

    public void union(int p, int q) {
        int proot = find(p), qroot = find(q);
        if (proot == qroot) return; // already handle cyclic graph
        if (sz[proot] > sz[qroot]) {
            id[qroot] = id[proot];
            sz[proot] += sz[qroot];
        } else {
            id[proot] = id[qroot];
            sz[qroot] += sz[proot];
        }
        root--;
    }
}
