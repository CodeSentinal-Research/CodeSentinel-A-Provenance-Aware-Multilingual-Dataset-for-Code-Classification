package Trees;

/*
========================================================================
PROBLEM: Count Paths of Length K from Every Node
========================================================================

Problem Statement:
------------------
Given a tree with n nodes numbered 0..n-1 and an integer K,
compute for each node the number of paths of length exactly K starting 
from that node.

Input Example:
---------------
n = 5, K = 2
edges = [[0,1],[0,2],[1,3],[1,4]]

Output:
--------
answer = [2,1,0,0,0]

Explanation:
- Node 0: paths of length 2 → (0-1-3), (0-1-4)
- Node 1: paths of length 2 → (1-0-2)
- Nodes 2,3,4: paths of length 2 → none

Approach (Tree Re-rooting + Subtree DP):
-----------------------------------------
1. DFS1: Compute dp[node][d] = number of nodes at distance d in the subtree.
   - dp[node][0] = 1 (node itself)
   - dp[node][d] = sum(dp[child][d-1]) for d ≥ 1

2. DFS2 (Re-rooting): Propagate contributions from parent / rest of tree:
   - For child c of parent p:
       dp[c][d] += dp[p][d-1] - dp[c][d-2]  (exclude child’s own subtree to avoid double counting)
   - This ensures paths going “up through parent” are counted.

3. Final answer for node i = dp[i][K]
========================================================================
*/

import java.util.*;

public class PathsLengthK {

    static int n, K;
    static List<List<Integer>> tree;
    static int[][] dp;
    static int[] answer;

    public static int[] countPathsOfLengthK(int N, int[][] edges, int k) {
        n = N;
        K = k;
        tree = new ArrayList<>();
        for (int i = 0; i < n; i++) tree.add(new ArrayList<>());

        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        dp = new int[n][K + 1];
        answer = new int[n];

        dfs1(0, -1); // Step 1: compute subtree distances
        dfs2(0, -1); // Step 2: re-root to include parent contribution

        for (int i = 0; i < n; i++) answer[i] = dp[i][K];
        return answer;
    }

    // DFS1: compute dp[node][d] for subtree
    private static void dfs1(int node, int parent) {
        dp[node][0] = 1; // distance 0 = node itself
        for (int child : tree.get(node)) {
            if (child == parent) continue;
            dfs1(child, node);
            for (int d = 1; d <= K; d++) {
                dp[node][d] += dp[child][d - 1];
            }
        }
    }

    // DFS2: re-root to include parent contributions
    private static void dfs2(int node, int parent) {
        for (int child : tree.get(node)) {
            if (child == parent) continue;

            int[] temp = new int[K + 1];
            for (int d = 1; d <= K; d++) {
                temp[d] = dp[node][d - 1];
                if (d - 2 >= 0) temp[d] -= dp[child][d - 2]; // exclude child's contribution
            }

            for (int d = 1; d <= K; d++) dp[child][d] += temp[d];

            dfs2(child, node);
        }
    }

    // Driver main
    public static void main(String[] args) {
        int n = 5;
        int[][] edges = {{0,1},{0,2},{1,3},{1,4}};
        int K = 2;

        int[] answer = countPathsOfLengthK(n, edges, K);
        System.out.println(Arrays.toString(answer)); // Output: [2,1,0,0,0]
    }
}